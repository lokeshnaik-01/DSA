// synchronise can't help in distributed systems
// we should use distributed concurrency control.

/*
    - Optimistic Concurrency Control (OCC)
    - Pessimistic Concurrency Control (PCC)
*/

/*
TRANSACTION- helps to achieve INTEGRITY, it means it helps to avoid INCONSISTIENCY in DB.
DB LOCKING- no other transaction should update the locked rows
    - there are two types of locks
        1. Shared Lock
        2. Exclusive lock
ISOLATION- If we have multiple transactions in parallel every transaction should be felt like they are working alone

- dirty read
- non repeatable read
- phantom read

isolation solved the above 3

there are 4 isoaltion levels
    1. read uncommited --> OCC
    2. read commited ----> OCC
    3. repetable read  --> PCC
    4. serialize --------> PCC

for OCC we use something like version (this was asked in baxter interview)
for PCC locks the critical section
    - can cause deadlock
*/