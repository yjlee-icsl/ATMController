# ATM Controller Project (C++)
A simple ATM controller written in C++.

# Build
```
mkdir build && cd build
cmake .. && make
```

# Run
## If you want to run using CLI inputs
Run the following command:
```
./atm_controller use_cli
```
## If you want to run using testcase files
Run the following command with a test case index (0~4):
```
./atm_controller from_file {test_case_index}
```

# TODO
1. Apply transactions (deposits and withdrawals) in real-time to the database file..
2. Add how to handle amounts that exceed the limit.