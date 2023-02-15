#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <term.h>
#include <stddef.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>

/* 20221224 структура для хранения отдельных токенов(частей строки)*/

typedef struct s_h_ret{
int		fd;
char	*f_name;
}t_h_ret;

typedef struct s_env{
    struct s_env    *prev;
    struct s_env    *next;
    int             ind;
    char            *key;
    char            *value;
}   t_env;

typedef struct s_node{
    struct s_node   *prev;
    struct s_node   *next;
    int             ind;
    int             type;
    int             prior;
    char            *token;
    int             fd;
	char*			f_name;
}   t_node;

typedef struct s_par{
    t_node  **list;
    t_env   **env;
}   t_par;


typedef enum s_type{
    _TEXT_  =   0,
    _SPC_   =   1,
    _D_QUT_ =   2,
    _S_QUT_ =   3,
    _OUT_F_ =   4,
    _APPD_  =   5,
    _IN_F_  =   6,
    _H_DOC_ =   7,
    _VAR_   =   8,
	_PIPE_	=	9,
	_ERROR_	=	-1
}   t_types;

/*20221222  from main, запуск и поддежка оснавного цикла работы 
in file minishell.c*/
int init(char **envp);
/*20221222 from init, разделение программы на оснавные логические модули
in file control_module*/
int	main_control(char **envp, char *line);
/*20221222 from main_control in file p_input_control*/
t_node	*p_input_control(char *line, int size);
/*20221222 p_input_control in filep_input_control*/
t_node	*p_input_params(char *line);
/*20221224 in file p_input_control */
int	p_for_spc(char *line, int i);
/*20221225 in file parsing_checkers */
int p_check_1(char *line, t_node **list, int i);
/*20221225 in file parsing_checkers */
int p_check_2(char *line, t_node **list, int i);
/*20221225 in file parsing_checkers */
int p_check_3(char *line, t_node **list, int i);
/*20221225 in file parsing_checkers */
int p_check_4(char *line, t_node **list, int i);
/*20221225 in file parsing_checkers */
int p_check_5(char *line, t_node **list, int i);
/*20221225 in file parsing_checkers_1*/
int p_check_6(char *line, t_node **list, int i);
int p_check_7(char *line, t_node **list, int i);
/*20230114 in file p_fin_check.c*/
int p_fin_check(t_node *list);
/*20230114 in file p_env.c*/
t_env   *p_env(char **envp);
/*20230115*/
int control_1(t_par *par);
void f_checker_1(t_par **par);
/*20230121*/
void f_checker_2(t_par **par);
/*20230126*/
int	f_find_max(int a, int b);
int f_var_checker(char *ptr, t_par *par);
char *f_env_ind(int ind, t_par **par);
int f_env_val_chk(char *val);
/*20230128*/
void    f_chk_3(char *ptr, t_node **temp);
void    f_chk_4(char *ptr, t_node **temp, t_par **par);
void    f_chk_5(char *ptr, t_node **temp);
void    f_chk_6(char *ptr, t_node **temp, t_par **par);
/*20230129*/
void f_h_doc(t_par **par);
t_h_ret f_h_read(t_par **par, char *dlmt);
char *f_h_cr_nm(void);
/*20230213*/
void f_h_writer_1(int i, int fd, t_par *par, char *chk);
void	ln_chk(char *line, t_par *par, int fd);
/*20230115*/
void    f_chk_7(char *ptr, t_node **temp);
void    f_chk_8(char *ptr, t_node **temp, t_par **par);
void f_checker_3(t_par **par);



/*UTILS*/
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char *str);
size_t	ft_strlen(const char*s);
int     ft_strncmp(const char *s1, const char *s2, size_t n);
void    lst_add(t_node **lst, char *tok, int type);
int	ft_strcmp(const char *s1, const char *s2, size_t n);

/*20230114*/
t_env	*ft_lstnew_env(char *key, char *value);
void	ft_lstadd_back_env(t_env **lst, t_env *new);
void    lst_add_env(t_env **env, char *key, char *value);
//------------------------
/*LIST_MAKE 20221224*/
t_node	*ft_lstnew(int type, char *token);
void	ft_lstadd_back(t_node **lst, t_node *new);
int     ft_lstsize(t_node *lst);
t_node	*ft_lstlast(t_node *lst);
void	ft_lstadd_front(t_node **lst, t_node *new);

/*LIST_DESTROY 20221224*/
void	ft_stack_del_node(t_node *node);
void	ft_stack_del(t_node **stack);
void	ft_env_del(t_env **env);
void	ft_env_del_node(t_env *node);
void	struct_free(t_par *par);
void	fd_clear(t_node **list);


/*PRINT_TEST*/
void printer_1(t_node *lst);
void printer_2(char **envp);
void printer_3(t_env *lst);