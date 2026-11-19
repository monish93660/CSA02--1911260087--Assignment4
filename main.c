#include <stdio.h>
#include <string.h>
#define MAX_ITEMS 50
#define MAX_COMBO 3

typedef struct { int day,month,year; } Date;
typedef struct { int hour,minute; } Time;
enum item_kind { PACKAGED, COOKED, COMBO };
typedef struct {
    char name[40];
    float price;
    int stock;
    enum item_kind kind;
    union {
        Date expiry;
        Time prepared;
        struct { int count; int item_id[MAX_COMBO]; } combo;
    } detail;
} Item;
typedef struct { int item_id,quantity; float line_total; } SaleLine;
typedef struct { SaleLine lines[MAX_ITEMS]; int count; float total; } Bill;

int find_item(const Item items[],int n,int id) {
    for(int i=0;i<n;i++) if(items[i].stock>=0 && i+1==id) return i;
    return -1;
}
int record_sale(Item items[],int n,int id,int qty,Bill *bill) {
    int idx=find_item(items,n,id);
    if(idx<0 || qty<=0 || items[idx].stock<qty) return 0;
    items[idx].stock-=qty;
    SaleLine *line=&bill->lines[bill->count++];
    line->item_id=id; line->quantity=qty;
    line->line_total=items[idx].price*qty;
    bill->total+=line->line_total;
    return 1;
}
int expiring_within_two_days(Date today,Date expiry) {
    /* This teaching example assumes dates are in the same month/year. */
    if(today.year!=expiry.year || today.month!=expiry.month) return 0;
    int days=expiry.day-today.day;
    return days>=0 && days<=2;
}
void expiry_warning(const Item items[],int n,Date today) {
    for(int i=0;i<n;i++) if(items[i].kind==PACKAGED &&
       expiring_within_two_days(today,items[i].detail.expiry))
        printf("Expiry warning: %s expires %02d/%02d/%04d\\n",items[i].name,
               items[i].detail.expiry.day,items[i].detail.expiry.month,
               items[i].detail.expiry.year);
}
void print_summary(const Bill *bill) {
    SaleLine sorted[MAX_ITEMS];
    for(int i=0;i<bill->count;i++) sorted[i]=bill->lines[i];
    for(int i=0;i<bill->count-1;i++) for(int j=0;j<bill->count-1-i;j++)
        if(sorted[j].line_total<sorted[j+1].line_total) {
            SaleLine t=sorted[j];sorted[j]=sorted[j+1];sorted[j+1]=t;
        }
    puts("Bill summary (revenue descending):");
    for(int i=0;i<bill->count;i++)
        printf("Item ID %d qty %d revenue %.2f\\n",
               sorted[i].item_id,sorted[i].quantity,sorted[i].line_total);
    printf("Total bill: %.2f\\n",bill->total);
}
int main(void) {
    Item items[3]={
        {"Milk",30.0f,10,PACKAGED,{.expiry={20,11,2026}}},
        {"Sandwich",55.0f,5,COOKED,{.prepared={10,30}}},
        {"Combo Meal",100.0f,4,COMBO,{.combo={2,{1,2}}}}
    };
    Bill bill={.count=0,.total=0};
    Date today={19,11,2026};
    if(!record_sale(items,3,1,2,&bill)) puts("Sale failed");
    if(!record_sale(items,3,2,1,&bill)) puts("Sale failed");
    if(!record_sale(items,3,2,99,&bill)) puts("Rejected: requested quantity exceeds stock");
    expiry_warning(items,3,today);
    print_summary(&bill);
    printf("Remaining Milk stock: %d\\n",items[0].stock);
    return 0;
}