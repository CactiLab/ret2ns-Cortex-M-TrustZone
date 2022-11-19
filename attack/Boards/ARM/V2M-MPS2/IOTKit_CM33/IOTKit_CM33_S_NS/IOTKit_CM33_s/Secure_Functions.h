/*----------------------------------------------------------------------------
 * Name:    Secure_Functions.h
 * Purpose: Function and Typedef Declarations to include into NonSecure Application.
 *----------------------------------------------------------------------------*/

/* Function declarations for Secure functions called from NonSecure application */
extern int32_t print_LCD_nsc(char*);
extern int32_t blxns_nsc(char*) ;

/* Define typedef for NonSecure callback function */ 
typedef int tdef_nsfunc_o_int_i_void(void);
extern int pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback);
