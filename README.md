# CSA02-<RegisterNumber>-Assignment4
Student: <Your Name>
Register Number: <Your Register Number>
Compiler: GCC <version>
Course Outcome: CO4 – Structures, unions, nested structures and storage classes

## Folder contents
- Task01: patient register redesigned using nested structures
- Task02: parcel tracking, nested structures, selection sort and pointer access
- Task03: tagged union for sensor readings and memory-size experiment
- Task04: structure pass-by-value defect repaired with pointers
- Task05: auto, static, extern and register examples (multi-file extern demo)
- Task06: canteen inventory and billing design challenge

## Compile and run
From the relevant task folder:
`gcc -std=c11 -Wall -Wextra main.c -o main`
Then run `./main` (Windows: `main.exe`).
Task05 extern multi-file version:
`gcc -std=c11 -Wall -Wextra main_extern.c token.c -o extern_demo`
Run `./extern_demo`.

## Submission evidence
Add actual terminal screenshots and any required input/output files to each folder. Record your actual GCC version (`gcc --version`) and exact commands. Do not invent machine-specific addresses or measured structure sizes. Each student must run all tasks and maintain their own repository.

## GitHub progressive commits
Create repository `CSA02-<RegisterNumber>-Assignment4`, then:
```bash
git init
git add README.md
git commit -m "Add assignment 4 README"
git add Task01
git commit -m "Complete task 1 patient data design"
git add Task02
git commit -m "Complete task 2 parcel structures"
git add Task03
git commit -m "Complete task 3 tagged union"
git add Task04
git commit -m "Complete task 4 structure pointers"
git add Task05
git commit -m "Complete task 5 storage classes"
git add Task06
git commit -m "Complete task 6 canteen billing"
git branch -M main
git remote add origin https://github.com/<username>/CSA02-<RegisterNumber>-Assignment4.git
git push -u origin main
```
Make it public or add faculty as collaborator if private. Each student must independently execute every task.
