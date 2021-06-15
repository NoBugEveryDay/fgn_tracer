#ifndef FGN_TRACE_H
#define FGN_TRACE_H

// Defined by FGN
#include <stdio.h>
#define FGN_TRACE_SWITCH

#define main(...) fgn_stack_depth=0; int main(__VA_ARGS__)

#define FGN_MPI_CHECK() int rank; MPI_Comm_rank(MPI_COMM_WORLD,&rank); if (rank==0)

#ifdef FGN_TRACE_SWITCH
    extern int fgn_stack_depth;
    #define FGN_TAB() {FGN_MPI_CHECK(){ int fgn_i; for (fgn_i = 0; fgn_i < fgn_stack_depth; fgn_i++) printf("    "); fflush(stdout);}}
    #define FGN_TRACE() {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_TRACE<<<\033[0m %s[%d] : %s()\n", __FILE__, __LINE__, __func__); fflush(stdout);}}
    #define FGN_PRINT_INT(VAR_NAME, VAR) {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_PRINT_INT<<<\033[0m %s[%d] : %s() - %s=%d\n", __FILE__, __LINE__, __func__, VAR_NAME, (int)(VAR)); fflush(stdout);}}
    #define FGN_PRINT_INT64(VAR_NAME, VAR) {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_PRINT_INT<<<\033[0m %s[%d] : %s() - %s=%lld\n", __FILE__, __LINE__, __func__, VAR_NAME, (long long int)(VAR)); fflush(stdout);}}
    #define FGN_PRINT_DOUBLE(VAR_NAME, VAR) {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_PRINT_INT<<<\033[0m %s[%d] : %s() - %s=%lf\n", __FILE__, __LINE__, __func__, VAR_NAME, (double)(VAR)); fflush(stdout);}}
    #define FGN_PRINT_STR(VAR_NAME, VAR) {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_PRINT_STR<<<\033[0m %s[%d] : %s() - %s=\"%s\"\n", __FILE__, __LINE__, __func__, VAR_NAME, VAR); fflush(stdout);}}
    #define FGN_PRINT_LINE() {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m---------------------------------------------------------------------\033[0m\n"); fflush(stdout);}}
    #define FGN_STEP_IN_FUNC() {FGN_MPI_CHECK(){ fgn_stack_depth++; FGN_TAB(); printf("\033[31m>>>FGN_STEP_IN_FUNC<<<\033[0m %s[%d] : %s()\n", __FILE__, __LINE__, __func__); fflush(stdout);}}
    #define FGN_STEP_OUT_FUNC() {FGN_MPI_CHECK(){ FGN_TAB(); fgn_stack_depth--; printf("\033[31m>>>FGN_STEP_OUT_FUNC<<<\033[0m %s[%d] : %s()\n", __FILE__, __LINE__, __func__); fflush(stdout);}}
    #define FGN_LOG(LOG_STR) {FGN_MPI_CHECK(){ FGN_TAB(); printf("\033[31m>>>FGN_LOG<<<\033[0m %s[%d] : %s() - %s\n", __FILE__, __LINE__, __func__, LOG_STR); fflush(stdout);}}
    #define FGN_EXIT() {printf("\033[31m>>>FGN_EXIT<<<\033[0m %s[%d] : %s()\n", __FILE__, __LINE__, __func__); fflush(stdout); exit(0);}
#else
    #define FGN_TAB()
    #define FGN_TRACE()
    #define FGN_PRINT_INT(VAR_NAME, VAR)
    #define FGN_PRINT_INT64(VAR_NAME, VAR)
    #define FGN_PRINT_DOUBLE(VAR_NAME, VAR)
    #define FGN_PRINT_STR(VAR_NAME, VAR)
    #define FGN_PRINT_LINE()
    #define FGN_STEP_IN_FUNC()
    #define FGN_STEP_OUT_FUNC()
    #define FGN_LOG(LOG_STR) 
    #define FGN_EXIT()
#endif

#endif