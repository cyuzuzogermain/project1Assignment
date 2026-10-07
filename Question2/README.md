# Mobile-Money Transaction System

## Sample input/output

This sample demonstrates three different menu operations and one invalid
transaction (a withdrawal larger than the balance).

Input provided: `1`, `50000`, `2`, `70000`, `3`, `5`

```
$ ./transaction_system

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 1
Enter deposit amount: 50000
Deposit successful.
Current balance: 50000 RWF

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 2
Enter withdrawal amount: 70000
Transaction rejected: Insufficient balance.

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 3
Current balance: 50000 RWF

===== MOBILE MONEY TRANSACTION SYSTEM =====

1. Deposit
2. Withdraw
3. Check Balance
4. Transaction Summary
5. Exit

Enter choice: 5
System terminated.
```

What this sample shows:

- **Deposit (choice 1):** 50000 RWF deposited, balance becomes 50000 RWF.
- **Invalid transaction (choice 2):** withdrawal of 70000 RWF is rejected
  because it exceeds the available balance.
- **Balance inquiry (choice 3):** displays the current balance.
- **Exit (choice 5):** terminates the program.

---

## How the program uses conditionals, loops, break, and continue

### Conditionals
The program uses a `switch` statement to dispatch on the agent's menu choice,
with separate `case` labels for deposit, withdrawal, balance inquiry,
transaction summary, and exit. Inside the deposit and withdrawal cases, further
`if` conditions validate the amount: a deposit or withdrawal is rejected when
the amount is not positive, and a withdrawal is additionally rejected when the
amount exceeds the current balance. A `default` case handles any menu choice
outside 1-5.

### Loops
A `while (1)` loop keeps the system running so the agent can perform multiple
transactions without restarting. The menu is reprinted at the top of each
iteration, and the loop only ends when the agent explicitly chooses Exit.

### `continue`
When invalid input is detected — for example, a non-numeric menu choice, a
non-positive deposit/withdrawal amount, or a menu choice outside the valid
range — the program prints an error message and executes `continue`. This skips
the rest of the current iteration and returns directly to the top of the loop,
where the menu is shown again. `continue` is used here precisely to avoid
duplicate code for "go back to the menu" after an error.

### `break`
`break` is used in two ways:

- **Inside each `case` in the switch:** `break` ends the switch handling for a
  successful operation so execution continues after the switch and the loop
  repeats with the menu. In the withdrawal case, `break` is also used after
  rejecting an overbalance withdrawal, so the program does not fall through to
  later cases.
- **Loop termination:** rather than relying on `break` to exit the outer `while`
  from inside the switch, the program uses a clean exit path for choice 5.
  (`break` would only exit the switch, not the enclosing loop.)

Together, the loop keeps the system alive, the conditionals validate operations,
`continue` returns to the menu on invalid input, and `break` controls the flow
within the switch and the successful-transaction paths.
