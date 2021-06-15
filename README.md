# fgn_tracer

## Introduction

fgn_tracer is a simple tracer for you when you start to analyze some huge C code project. It can help you understand the function call dependency and print important variables easily. You ONLY need to add `#include "fgn_tracer.h"` to the project and add macros to anywhere you want to trace.

## Feature

![example.png](https://raw.githubusercontent.com/NoBugEveryDay/fgn_tracer/master/example/example.png)

- Trace any function call you want.
- Print any variable at anywhere you want.
- The output of the tracer is start with red character to distinguish from normal output.
- Humanized indentation helps to understand the dependency of function call.
- Each trace shows the filename,  line number and the function name of its location
-  When you don't need the tracer anymore, just comment `#define FGN_TRACE_SWITCH` in `fgn_tracer.h` and recompile the project. Then, all the tracer will be ignored and it will not affect performance at all
- Support project with MPI. Only the first process will print output except the `FGN_EXIT()`

## Usage

1. Copy `fgn_trancer.h` to the include directory of the project
2. Add `#include "fgn_tracer.h"` to a suitable location of the project. A good idea is add it to a generic header in the project. For example, in MPI library code, add it to the `mpi.h`, so you can just add it once. Add `#include "fgn_tracer.h"` to multiple location in a project is OK, there will be no conflict among them. Thus, don't be nervous if there "undefined reference" errors occur when compiling. Just add enough `#include "fgn_tracer.h"` to the project.
3. Add macros to anywhere you want to trace
4. When you don't need the tracer, just comment `#define FGN_TRACE_SWITCH` in `fgn_tracer.h` and recompile the project. Then, all the tracer will be ignored and it will not affect performance at all

The functions of fgn_tracer are as follows

| Function name                    | Description                                                  |
| -------------------------------- | ------------------------------------------------------------ |
| FGN_TRACE()                      | Print a log to indicate the program runs to here             |
| FGN_PRINT_INT(string, int)       | Print a int variable. If the variable is not a int, it will be convert to int. |
| FGN_PRINT_INT64(string, int64)   | Print a int64 variable. If the variable is not a int64, it will be convert to int64. |
| FGN_PRINT_DOUBLE(string, double) | Print a double variable. If the variable is not a double, it will be convert to double. |
| FGN_PRINT_STR(string, string)    | Print a string variable.                                     |
| FGN_PRINT_LINE()                 | Print a Dividing line.                                       |
| FGN_STEP_IN_FUNC()               | Print a log to indicate the program step into a function. Call it at the entrance of a function. |
| FGN_STEP_OUT_FUNC()              | Print a log to indicate the program step out a function. Call it before the exit of a function, for example before `return` |
| FGN_LOG(LOG_STR)                 | Print a log                                                  |
| FGN_EXIT()                       | Print a log and exit the execution.                          |

## Example

A simple example is in `example` directory.

