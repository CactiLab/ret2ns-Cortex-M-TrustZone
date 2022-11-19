/*----------------------------------------------------------------------------
 * Name:    Secure_Functions.h
 * Purpose: Function and Typedef Declarations to include into NonSecure Application.
 *----------------------------------------------------------------------------*/

/* Define typedef for NonSecure callback function */ 
typedef int32_t (*NonSecure_funcptr)(uint32_t);

/* Function declarations for Secure functions called from NonSecure application */
extern int32_t Secure_LED_On (uint32_t);
extern int32_t Secure_LED_Off(uint32_t);
extern int32_t Secure_LED_On_callback (NonSecure_funcptr);
extern int32_t Secure_LED_Off_callback(NonSecure_funcptr);
extern void    Secure_printf (char*);

extern int32_t print_LCD_nsc(char*);
extern int32_t blxns_nsc(char*) ;

/* ======== Secure callable functions initialization ======== */

typedef int tdef_nsfunc_o_int_i_void(void);
extern int pass_nsfunc_ptr_o_int_i_void(tdef_nsfunc_o_int_i_void *callback);
