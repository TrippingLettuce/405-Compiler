/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>

#include "symbolTable.h"
#include "AST.h"
#include "IRcode.h"
#include "assembly.h"
#include "calculator.h"


extern int yylex();
extern int yyparse();
extern FILE* yyin;
void yyerror(const char* s);

#define IN_ELSE_BLOCK 0 // Currently navigating through 'else' block.
#define IN_IF_BLOCK 1 // Currently navigating through 'if' block.
#define RUN_ELSE_BLOCK 0 // Execution of 'else' block is scheduled.
#define RUN_IF_BLOCK 1 // Execution of 'if' block is scheduled.
#define UPDATE_IF_ELSE 0 // Update the 'if-else' state.

#define UPDATE_WHILE 1 // Update the 'while' loop state.

// Constants for determining the output section in the intermediate code and the MIPS file.
#define IR_CODE 0 // Main section of the intermediate code (default).
#define IR_FUNC 1 // Function and loop sections of the intermediate code.
#define TEMP_MIPS 0  // Main section of the MIPS code (default).
#define MIPS_CODE 1  // Variable declaration section of the MIPS code.
#define MIPS_FUNC 2  // Function and loop sections of the MIPS code.

// Tracking variables.
char currentScope[50]; // The current scope which can be 'global' or the function's name.
char IDArg[50]; // Stores the name of the ID argument temporarily.
int argIsID = 0; // Flag to indicate if an argument is an ID.
int argCounter = 0; // Tracks the number of arguments.
char *args[50]; // Array of argument names.
char **argptr = args; // Pointer to the array of argument names.

// Current operator storage for mathematical and conditional operations.
char operator; // Current operator for mathematical expressions.
char op; // Current operator for conditions.

// Temporary storage for two operands in a binary mathematical operation.
char num1[50]; // First operand.
char num2[50]; // Second operand.

// Control flags for 'if-else' and 'while' constructs.
int runIfElseBlock = 0; // Indicates whether to execute the 'if' block (1) or the 'else' block (0).
int ifElseCurrentBlock = 0; // Shows current active block: 'if' block (1) or 'else' block (0).
int runWhileBlock = 0; // Indicates whether to execute the 'while' block (1) or exit the loop (0).
int inElseOrWhile = 0; // Flag indicating which construct to update: 'if-else' (0) or 'while' loop (1).

// Variables related to 'while' loops.
int numOfWhileLoops = 0; // Counts the number of 'while' loops, used for naming 'while' loops in MIPS.
char whileName[50]; // Holds the name of the current 'while' loop for MIPS naming.
int registerCounter = 0; // Tracks the number of registers used for parameters in MIPS.

// Scope initialization and symbol table.
char scope[50] = "G"; // Initialize the scope as 'global'.



#line 138 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_CHAR = 3,                       /* CHAR  */
  YYSYMBOL_INT = 4,                        /* INT  */
  YYSYMBOL_FLOAT = 5,                      /* FLOAT  */
  YYSYMBOL_VOID = 6,                       /* VOID  */
  YYSYMBOL_IF = 7,                         /* IF  */
  YYSYMBOL_ELSE = 8,                       /* ELSE  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_WRITE = 10,                     /* WRITE  */
  YYSYMBOL_RETURN = 11,                    /* RETURN  */
  YYSYMBOL_COMMA = 12,                     /* COMMA  */
  YYSYMBOL_SEMICOLON = 13,                 /* SEMICOLON  */
  YYSYMBOL_NEWLINECHAR = 14,               /* NEWLINECHAR  */
  YYSYMBOL_DEQ = 15,                       /* DEQ  */
  YYSYMBOL_NOTEQ = 16,                     /* NOTEQ  */
  YYSYMBOL_LEQ = 17,                       /* LEQ  */
  YYSYMBOL_GEQ = 18,                       /* GEQ  */
  YYSYMBOL_LT = 19,                        /* LT  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_ADD = 22,                       /* ADD  */
  YYSYMBOL_MULTIPLY = 23,                  /* MULTIPLY  */
  YYSYMBOL_SUB = 24,                       /* SUB  */
  YYSYMBOL_DIV = 25,                       /* DIV  */
  YYSYMBOL_EXPONENT = 26,                  /* EXPONENT  */
  YYSYMBOL_LPAREN = 27,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 28,                    /* RPAREN  */
  YYSYMBOL_LBRACKET = 29,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 30,                  /* RBRACKET  */
  YYSYMBOL_LBRACE = 31,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 32,                    /* RBRACE  */
  YYSYMBOL_NUMBER = 33,                    /* NUMBER  */
  YYSYMBOL_FLOATNUM = 34,                  /* FLOATNUM  */
  YYSYMBOL_STRINGID = 35,                  /* STRINGID  */
  YYSYMBOL_CHARID = 36,                    /* CHARID  */
  YYSYMBOL_ID = 37,                        /* ID  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_Program = 39,                   /* Program  */
  YYSYMBOL_DeclList = 40,                  /* DeclList  */
  YYSYMBOL_Decl = 41,                      /* Decl  */
  YYSYMBOL_FuncDecl = 42,                  /* FuncDecl  */
  YYSYMBOL_43_1 = 43,                      /* $@1  */
  YYSYMBOL_44_2 = 44,                      /* $@2  */
  YYSYMBOL_45_3 = 45,                      /* $@3  */
  YYSYMBOL_46_4 = 46,                      /* $@4  */
  YYSYMBOL_ParamDeclList = 47,             /* ParamDeclList  */
  YYSYMBOL_ParamDecl = 48,                 /* ParamDecl  */
  YYSYMBOL_ArgDeclList = 49,               /* ArgDeclList  */
  YYSYMBOL_ArgDecl = 50,                   /* ArgDecl  */
  YYSYMBOL_Block = 51,                     /* Block  */
  YYSYMBOL_BlockDeclList = 52,             /* BlockDeclList  */
  YYSYMBOL_BlockDecl = 53,                 /* BlockDecl  */
  YYSYMBOL_StmtList = 54,                  /* StmtList  */
  YYSYMBOL_VarDecl = 55,                   /* VarDecl  */
  YYSYMBOL_Expr = 56,                      /* Expr  */
  YYSYMBOL_IDEQExpr = 57,                  /* IDEQExpr  */
  YYSYMBOL_MathStmt = 58,                  /* MathStmt  */
  YYSYMBOL_Math = 59,                      /* Math  */
  YYSYMBOL_Operator = 60,                  /* Operator  */
  YYSYMBOL_CompOperator = 61,              /* CompOperator  */
  YYSYMBOL_ArrDecl = 62,                   /* ArrDecl  */
  YYSYMBOL_WhileStmt = 63,                 /* WhileStmt  */
  YYSYMBOL_64_5 = 64,                      /* $@5  */
  YYSYMBOL_65_6 = 65,                      /* $@6  */
  YYSYMBOL_IfStmt = 66,                    /* IfStmt  */
  YYSYMBOL_67_7 = 67,                      /* $@7  */
  YYSYMBOL_68_8 = 68,                      /* $@8  */
  YYSYMBOL_69_9 = 69,                      /* $@9  */
  YYSYMBOL_ElseStmt = 70,                  /* ElseStmt  */
  YYSYMBOL_Condition = 71                  /* Condition  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  38
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   224

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  34
/* YYNRULES -- Number of rules.  */
#define YYNRULES  103
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  196

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   292


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   127,   127,   163,   169,   177,   182,   187,   192,   197,
     205,   205,   232,   232,   259,   259,   286,   286,   315,   321,
     329,   329,   340,   351,   365,   371,   379,   379,   385,   391,
     397,   407,   414,   420,   428,   433,   438,   443,   450,   450,
     456,   466,   499,   564,   594,   662,   695,   760,   802,   811,
     826,   828,   869,   950,   997,  1025,  1078,  1093,  1102,  1174,
    1220,  1290,  1368,  1423,  1445,  1467,  1492,  1603,  1607,  1612,
    1613,  1614,  1630,  1642,  1643,  1644,  1648,  1649,  1650,  1651,
    1654,  1655,  1656,  1657,  1658,  1659,  1663,  1668,  1673,  1715,
    1757,  1769,  1757,  1780,  1780,  1785,  1780,  1807,  1807,  1809,
    1828,  1928,  1957,  1975
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "CHAR", "INT", "FLOAT",
  "VOID", "IF", "ELSE", "WHILE", "WRITE", "RETURN", "COMMA", "SEMICOLON",
  "NEWLINECHAR", "DEQ", "NOTEQ", "LEQ", "GEQ", "LT", "GT", "EQ", "ADD",
  "MULTIPLY", "SUB", "DIV", "EXPONENT", "LPAREN", "RPAREN", "LBRACKET",
  "RBRACKET", "LBRACE", "RBRACE", "NUMBER", "FLOATNUM", "STRINGID",
  "CHARID", "ID", "$accept", "Program", "DeclList", "Decl", "FuncDecl",
  "$@1", "$@2", "$@3", "$@4", "ParamDeclList", "ParamDecl", "ArgDeclList",
  "ArgDecl", "Block", "BlockDeclList", "BlockDecl", "StmtList", "VarDecl",
  "Expr", "IDEQExpr", "MathStmt", "Math", "Operator", "CompOperator",
  "ArrDecl", "WhileStmt", "$@5", "$@6", "IfStmt", "$@7", "$@8", "$@9",
  "ElseStmt", "Condition", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-145)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      14,   -35,   -25,   -23,    -6,  -145,  -145,     8,   109,  -145,
     103,    61,  -145,    14,  -145,  -145,  -145,     0,    20,  -145,
    -145,  -145,    13,    26,    50,    40,    49,    55,    81,    85,
      28,    98,   113,   120,   131,    47,   114,    94,  -145,  -145,
     104,  -145,   141,  -145,  -145,  -145,    23,  -145,  -145,    82,
    -145,  -145,  -145,   119,   119,  -145,  -145,  -145,   127,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,
     148,   149,   150,    65,  -145,    79,  -145,  -145,  -145,  -145,
    -145,    67,   152,   134,    95,  -145,   105,   154,   136,   105,
     156,   138,   105,   105,   121,   121,   121,   121,   143,   144,
     142,  -145,  -145,  -145,  -145,   114,  -145,  -145,  -145,  -145,
     160,   114,   155,    66,   140,   145,   146,   147,   166,  -145,
     167,   151,  -145,   168,   157,   158,  -145,  -145,  -145,  -145,
    -145,  -145,   159,   153,   161,   -30,  -145,  -145,   171,   162,
    -145,  -145,    63,  -145,  -145,  -145,  -145,   164,   105,  -145,
     164,  -145,   164,   164,  -145,  -145,  -145,  -145,  -145,   164,
     164,  -145,   175,   176,   178,   181,    25,  -145,  -145,  -145,
    -145,  -145,  -145,  -145,  -145,  -145,  -145,  -145,   163,   165,
     169,   173,    25,  -145,  -145,  -145,  -145,   187,    33,    34,
     183,  -145,  -145,   164,  -145,  -145
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      38,     0,     0,     0,     0,    93,    90,     0,     0,    50,
       0,     0,     2,     4,     5,     7,     6,    38,     0,    49,
       8,     9,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    26,     0,     1,     3,
       0,    39,     0,    48,    43,    14,     0,    41,    12,     0,
      45,    16,    10,     0,     0,    56,    54,    53,     0,    63,
      64,    65,    62,    76,    78,    77,    79,    74,    69,    70,
      72,    73,     0,    71,    66,    68,    75,    27,    28,    29,
      30,     0,    25,     0,     0,    57,    20,     0,     0,    20,
       0,     0,    20,    20,     0,     0,     0,     0,     0,     0,
       0,    42,    46,    44,    47,    26,    72,    73,    71,    67,
       0,    26,     0,    71,     0,     0,     0,     0,    19,    87,
       0,     0,    86,     0,     0,     0,    80,    85,    83,    84,
      81,    82,     0,     0,     0,     0,    94,    91,     0,     0,
      61,    24,     0,    51,    23,    21,    22,     0,    20,    89,
       0,    88,     0,     0,    99,   102,   103,   101,   100,     0,
       0,    55,     0,     0,     0,     0,    38,    15,    18,    13,
      17,    11,    95,    92,    52,    58,    60,    59,     0,     0,
       0,     0,    33,    35,    34,    36,    37,    97,     0,     0,
       0,    31,    32,     0,    96,    98
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -145,  -145,   185,  -145,  -145,  -145,  -145,  -145,  -145,   -88,
    -145,   -57,  -145,  -144,    17,  -145,   -17,  -124,  -145,   184,
     129,    68,  -145,    62,  -145,  -116,  -145,  -145,  -114,  -145,
    -145,  -145,  -145,   170
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,    11,    12,    13,    14,    93,    89,    86,    92,   117,
     118,    81,    82,   167,   181,   182,    15,    16,    17,    18,
      74,    75,    76,   132,    19,    20,    27,   160,    21,    26,
     159,   187,   194,    98
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      41,   121,    22,   157,   124,   125,   169,   158,   170,   171,
       7,     8,    23,     9,    24,   172,   173,     1,     2,     3,
       4,     5,    28,     6,     7,     8,    44,     9,   178,   179,
     180,    25,     5,    43,     6,     7,     8,    40,     9,    47,
      45,    57,   184,    29,    46,    30,    44,    47,   139,   195,
     185,    10,   186,    48,   141,    87,    88,    49,   184,    58,
     168,    38,    10,    50,    46,    49,   185,    52,   186,    63,
      64,    65,    66,    67,    68,    69,    53,    51,   104,   143,
      70,    71,    54,    72,    73,    63,    64,    65,    66,    67,
      68,    69,   105,   105,    55,   110,   163,   107,    56,   164,
     108,    63,    64,    65,    66,    67,    68,    69,   114,   115,
     116,    59,   106,   107,    90,    91,   108,    63,    64,    65,
      66,    67,    68,    69,    35,    84,    60,    83,   106,   107,
      36,    36,   113,    61,    37,    37,   126,   127,   128,   129,
     130,   131,    31,    32,    62,    33,    34,    77,    78,   183,
      79,    80,    94,    95,    85,    96,    97,   133,   134,   135,
     100,   101,   102,   103,   111,   183,   112,   119,   120,   122,
     123,   136,   137,   140,   138,   147,   142,   144,   148,   150,
     149,   151,   145,   146,   161,   152,   153,   155,   174,   175,
     162,   176,   154,   166,   177,   193,    50,   156,    39,   192,
     188,    42,   189,   191,   109,     0,   190,     0,     0,     0,
     165,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    99
};

static const yytype_int16 yycheck[] =
{
      17,    89,    37,    33,    92,    93,   150,    37,   152,   153,
      10,    11,    37,    13,    37,   159,   160,     3,     4,     5,
       6,     7,    14,     9,    10,    11,    13,    13,     3,     4,
       5,    37,     7,    13,     9,    10,    11,    37,    13,    13,
      27,    13,   166,    35,    31,    37,    13,    13,   105,   193,
     166,    37,   166,    27,   111,    32,    33,    31,   182,    31,
     148,     0,    37,    13,    31,    31,   182,    27,   182,    22,
      23,    24,    25,    26,    27,    28,    27,    27,    13,    13,
      33,    34,    27,    36,    37,    22,    23,    24,    25,    26,
      27,    28,    27,    27,    13,    28,    33,    34,    13,    36,
      37,    22,    23,    24,    25,    26,    27,    28,     3,     4,
       5,    13,    33,    34,    32,    33,    37,    22,    23,    24,
      25,    26,    27,    28,    21,    21,    13,    33,    33,    34,
      27,    27,    37,    13,    31,    31,    15,    16,    17,    18,
      19,    20,    33,    34,    13,    36,    37,    33,    34,   166,
      36,    37,    33,    34,    13,    36,    37,    95,    96,    97,
      33,    13,    13,    13,    12,   182,    32,    13,    32,    13,
      32,    28,    28,    13,    32,    28,    21,    37,    12,    28,
      13,    13,    37,    37,    13,    28,    28,    34,    13,    13,
      28,    13,    33,    29,    13,     8,    13,    36,    13,   182,
      37,    17,    37,    30,    75,    -1,    37,    -1,    -1,    -1,
     142,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    54
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    10,    11,    13,
      37,    39,    40,    41,    42,    54,    55,    56,    57,    62,
      63,    66,    37,    37,    37,    37,    67,    64,    14,    35,
      37,    33,    34,    36,    37,    21,    27,    31,     0,    40,
      37,    54,    57,    13,    13,    27,    31,    13,    27,    31,
      13,    27,    27,    27,    27,    13,    13,    13,    31,    13,
      13,    13,    13,    22,    23,    24,    25,    26,    27,    28,
      33,    34,    36,    37,    58,    59,    60,    33,    34,    36,
      37,    49,    50,    33,    21,    13,    45,    32,    33,    44,
      32,    33,    46,    43,    33,    34,    36,    37,    71,    71,
      33,    13,    13,    13,    13,    27,    33,    34,    37,    58,
      28,    12,    32,    37,     3,     4,     5,    47,    48,    13,
      32,    47,    13,    32,    47,    47,    15,    16,    17,    18,
      19,    20,    61,    61,    61,    61,    28,    28,    32,    49,
      13,    49,    21,    13,    37,    37,    37,    28,    12,    13,
      28,    13,    28,    28,    33,    34,    36,    33,    37,    68,
      65,    13,    28,    33,    36,    59,    29,    51,    47,    51,
      51,    51,    51,    51,    13,    13,    13,    13,     3,     4,
       5,    52,    53,    54,    55,    63,    66,    69,    37,    37,
      37,    30,    52,     8,    70,    51
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    40,    40,    41,    41,    41,    41,    41,
      43,    42,    44,    42,    45,    42,    46,    42,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    52,    52,    53,    53,    53,    53,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      56,    56,    56,    56,    56,    56,    56,    56,    56,    56,
      56,    56,    56,    56,    56,    56,    57,    58,    58,    59,
      59,    59,    59,    59,    59,    59,    60,    60,    60,    60,
      61,    61,    61,    61,    61,    61,    62,    62,    62,    62,
      64,    65,    63,    67,    68,    69,    66,    70,    70,    71,
      71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     1,
       0,     7,     0,     7,     0,     7,     0,     7,     3,     1,
       0,     2,     2,     2,     3,     1,     0,     1,     1,     1,
       1,     3,     2,     1,     1,     1,     1,     1,     0,     2,
       1,     3,     4,     3,     4,     3,     4,     4,     2,     1,
       1,     4,     7,     3,     3,     6,     3,     2,     7,     7,
       7,     5,     3,     3,     3,     3,     3,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     5,     6,     6,
       0,     0,     7,     0,     0,     0,     9,     0,     2,     3,
       3,     3,     3,     3
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  switch (yykind)
    {
    case YYSYMBOL_ID: /* ID  */
#line 119 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 952 "parser.tab.c"
        break;

      default:
        break;
    }
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: DeclList  */
#line 127 "parser.y"
                  {
		// ast
		(yyval.ast) = (yyvsp[0].ast);

		printf("\n\n ---------------------" RESET);
		printf(BPINK " AST STARTED " RESET);
		printf("--------------------- \n\n" RESET);

		// print the ast
		//printAST($$,0);

		// output the end of the ast
		printf("\n\n ---------------------" RESET);
		printf(PINK " AST ENDED " RESET);
		printf("--------------------- \n\n" RESET);

		// append the two ir code files to each other
		appendFiles("IRFuncs.ir", "IRcode.ir");

		// end mips code
		addEndLoop(); // add the endloop function to the bottom of mips for any loops to jump to to get to main
		createEndOfAssemblyCode(); // add the end line of mips to kill the program

		// append the three mips files to each other
		appendFiles("tempMIPS.asm", "MIPScode.asm");
		printf("\n");
		appendFiles("MIPSfuncs.asm", "MIPScode.asm");

		// output that mips was generated
		printf("\n\n ---------------------" RESET);
		printf(BPINK " MIPS GENERATED " RESET);
		printf("--------------------- \n\n" RESET);

}
#line 1375 "parser.tab.c"
    break;

  case 3: /* DeclList: Decl DeclList  */
#line 163 "parser.y"
                             {

				// ast
				(yyvsp[-1].ast)->left = (yyvsp[0].ast);
				(yyval.ast) = (yyvsp[-1].ast);

			}
#line 1387 "parser.tab.c"
    break;

  case 4: /* DeclList: Decl  */
#line 169 "parser.y"
                                 {

				// ast
				(yyval.ast) = (yyvsp[0].ast);

}
#line 1398 "parser.tab.c"
    break;

  case 5: /* Decl: FuncDecl  */
#line 177 "parser.y"
                    { // function declaration

			// ast
			(yyval.ast) = (yyvsp[0].ast);

		}
#line 1409 "parser.tab.c"
    break;

  case 6: /* Decl: VarDecl  */
#line 182 "parser.y"
                            { // variable declaration

			// ast
			(yyval.ast) = (yyvsp[0].ast);

		}
#line 1420 "parser.tab.c"
    break;

  case 7: /* Decl: StmtList  */
#line 187 "parser.y"
                             { // statement declaration list

			// ast
			(yyval.ast) = (yyvsp[0].ast);

		}
#line 1431 "parser.tab.c"
    break;

  case 8: /* Decl: WhileStmt  */
#line 192 "parser.y"
                              { // while statement declaration
			
			// ast
			(yyval.ast) = (yyvsp[0].ast);
	
		}
#line 1442 "parser.tab.c"
    break;

  case 9: /* Decl: IfStmt  */
#line 197 "parser.y"
                               { // if statement declaration

			// ast
			(yyval.ast) = (yyvsp[0].ast);
	
}
#line 1453 "parser.tab.c"
    break;

  case 10: /* $@1: %empty  */
#line 205 "parser.y"
                                                        { printf(BORANGE "RULE: (VOID) Function Initialization \n\n" RESET); // void function declaration
								
								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable((yyvsp[-1].string),"VOID"); // add void function to symbol table
								strcpy(scope,(yyvsp[-1].string)); // set scope to function name

								// ir code
								createFunctionHeader((yyvsp[-1].string)); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction((yyvsp[-1].string)); // create function
	
							// second part of the function, including parameter list, right parentheses, and block
							}
#line 1474 "parser.tab.c"
    break;

  case 11: /* FuncDecl: VOID ID LPAREN $@1 ParamDeclList RPAREN Block  */
#line 220 "parser.y"
                                                                                     { printf(BGREEN "\nVoid Function End.\n" RESET); // void function end

								// ast
								(yyval.ast) = AST_assignment("FNC",(yyvsp[-6].string),(yyvsp[-5].string)); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips
						

						}
#line 1492 "parser.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 232 "parser.y"
                                                                  {printf(BORANGE "RULE: (INT) Function Initialization \n\n" RESET); // int function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable((yyvsp[-1].string),"INT"); // add int function to symbol table
								strcpy(scope,(yyvsp[-1].string)); // set scope to function name

								// ir code
								createFunctionHeader((yyvsp[-1].string)); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction((yyvsp[-1].string)); // create function
						 
						 	// second part of the function, including parameter list, right parentheses, and block
						 	}
#line 1513 "parser.tab.c"
    break;

  case 13: /* FuncDecl: INT ID LPAREN $@2 ParamDeclList RPAREN Block  */
#line 247 "parser.y"
                                                                                     { printf(BGREEN "\nInt Function End.\n" RESET); // void function end

								// ast
								(yyval.ast) = AST_assignment("FNC",(yyvsp[-6].string),(yyvsp[-5].string)); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips code
								endMIPSFunction(); // end function in mips

						
						}
#line 1531 "parser.tab.c"
    break;

  case 14: /* $@3: %empty  */
#line 259 "parser.y"
                                                                   {printf(BORANGE "RULE: (Char) Function Initialization \n\n" RESET); // char function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable((yyvsp[-1].string),"CHR"); // add char function to symbol table
								strcpy(scope,(yyvsp[-1].string)); // set scope to function name

								// ir code
								createFunctionHeader((yyvsp[-1].string)); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction((yyvsp[-1].string)); // create function
						 
						 	// second part of the function, including parameter list, right parentheses, and block
							}
#line 1552 "parser.tab.c"
    break;

  case 15: /* FuncDecl: CHAR ID LPAREN $@3 ParamDeclList RPAREN Block  */
#line 274 "parser.y"
                                                                                     { printf(BGREEN "\nChar Function End.\n" RESET); // char function end

								// ast
								(yyval.ast) = AST_assignment("FNC",(yyvsp[-6].string),(yyvsp[-5].string)); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips

						
						}
#line 1570 "parser.tab.c"
    break;

  case 16: /* $@4: %empty  */
#line 286 "parser.y"
                                                                    {printf(BORANGE "RULE: (Float) Function Initialization \n\n" RESET); // float function declaration

								// symbol table
								symTabAccess(); // access symbol table
								addSymbolTable((yyvsp[-1].string),"FLT"); // add float function to symbol table
								strcpy(scope,(yyvsp[-1].string)); // set scope to function name

								// ir code
								createFunctionHeader((yyvsp[-1].string)); // create function
								changeIRFile(IR_FUNC); // change file to print block to the function IR code file

								// mips
								createMIPSFunction((yyvsp[-1].string)); // create function
								
							// second part of the function, including parameter list, right parentheses, and block
						 	}
#line 1591 "parser.tab.c"
    break;

  case 17: /* FuncDecl: FLOAT ID LPAREN $@4 ParamDeclList RPAREN Block  */
#line 301 "parser.y"
                                                                                     { printf(BGREEN "\nFloat Function End.\n" RESET); // float function end

								// ast
								(yyval.ast) = AST_assignment("FNC",(yyvsp[-6].string),(yyvsp[-5].string)); // add the function to the ast

								// ir code
								changeIRFile(IR_CODE); // change file back to main file

								// mips
								endMIPSFunction(); // end function in mips
 
}
#line 1608 "parser.tab.c"
    break;

  case 18: /* ParamDeclList: ParamDecl COMMA ParamDeclList  */
#line 315 "parser.y"
                                             { // list of parameters separated by commas

					// ast
					(yyvsp[-2].ast)->left = (yyvsp[-1].string);
					(yyval.ast) = (yyvsp[-2].ast);

				}
#line 1620 "parser.tab.c"
    break;

  case 19: /* ParamDeclList: ParamDecl  */
#line 321 "parser.y"
                                              { // or single parameter

					// ast
					(yyval.ast) = (yyvsp[0].ast);

				}
#line 1631 "parser.tab.c"
    break;

  case 21: /* ParamDecl: INT ID  */
#line 329 "parser.y"
                                 { printf(BORANGE "RULE: (INT) Parameter Initialization \n\n" RESET); // integer parameter declaration

					// symbol table
					addItem((yyvsp[0].string),"PAR","INT",scope,0); // add integer parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);


				}
#line 1648 "parser.tab.c"
    break;

  case 22: /* ParamDecl: FLOAT ID  */
#line 340 "parser.y"
                                             { printf(BORANGE "RULE: (Float) Parameter Initialization \n\n" RESET); // float parameter declaration

					// symbol table
					addItem((yyvsp[0].string),"PAR","FLT",scope,0); // add float parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);


				}
#line 1665 "parser.tab.c"
    break;

  case 23: /* ParamDecl: CHAR ID  */
#line 351 "parser.y"
                                            { printf(BORANGE "RULE: (Char) Parameter Initialization \n\n" RESET); // char parameter declaration

					// symbol table
					addItem((yyvsp[0].string),"PAR","CHR",scope,0); // add char parameter to symbol table

					// ir code
					printf(BLUE "IR Code" RESET);
					printf(RED " NOT " RESET);
					printf(BLUE "Created\n" RESET);
					

}
#line 1682 "parser.tab.c"
    break;

  case 24: /* ArgDeclList: ArgDecl COMMA ArgDeclList  */
#line 365 "parser.y"
                                       { // recursive list of arguments

					// ast
					(yyvsp[-2].ast)->left = (yyvsp[-1].string);
					(yyval.ast) = (yyvsp[-2].ast);

				}
#line 1694 "parser.tab.c"
    break;

  case 25: /* ArgDeclList: ArgDecl  */
#line 371 "parser.y"
                                            { // or single argument

					// ast
					(yyval.ast) = (yyvsp[0].ast);

				}
#line 1705 "parser.tab.c"
    break;

  case 27: /* ArgDecl: NUMBER  */
#line 379 "parser.y"
                         { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, (yyvsp[0].string)); // number argument

				argptr[argCounter] = (yyvsp[0].string); // add number to argument array
				argCounter++; // increment argument counter


			}
#line 1717 "parser.tab.c"
    break;

  case 28: /* ArgDecl: FLOATNUM  */
#line 385 "parser.y"
                                     { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, (yyvsp[0].string)); // float argument

				argptr[argCounter] = (yyvsp[0].string); // add float number to argument array
				argCounter++; // increment argument counter


			}
#line 1729 "parser.tab.c"
    break;

  case 29: /* ArgDecl: CHARID  */
#line 391 "parser.y"
                                   { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, (yyvsp[0].string)); // char argument

				argptr[argCounter] = (yyvsp[0].string); // add char to argument array
				argCounter++; // increment argument counter
				

			}
#line 1741 "parser.tab.c"
    break;

  case 30: /* ArgDecl: ID  */
#line 397 "parser.y"
                               { printf(BORANGE "RULE: Parameter Set = %s\n\n" RESET, getValue((yyvsp[0].string), "G")); // id argument

				argptr[argCounter] = getValue((yyvsp[0].string), "G"); // add id value to argument array
				strcpy(IDArg, (yyvsp[0].string)); // copy the name of the id into temporary IDArg variable
				argIsID = 1; // set flag so it knows the parameter is an ID, not a number
				argCounter++; // increment argument counter

}
#line 1754 "parser.tab.c"
    break;

  case 31: /* Block: LBRACKET BlockDeclList RBRACKET  */
#line 407 "parser.y"
                                       { // blockDeclList is the recursive list of statements inside the block

	strcpy(scope,"G"); // reset scope back to global after statements are parsed

}
#line 1764 "parser.tab.c"
    break;

  case 32: /* BlockDeclList: BlockDecl BlockDeclList  */
#line 414 "parser.y"
                                       { // recursive list of statements

				// ast
				(yyvsp[-1].ast)->left = (yyvsp[0].ast);
				(yyval.ast) = (yyvsp[-1].ast);

		}
#line 1776 "parser.tab.c"
    break;

  case 33: /* BlockDeclList: BlockDecl  */
#line 420 "parser.y"
                              { // or single statement

				// ast
				(yyval.ast) = (yyvsp[0].ast);

}
#line 1787 "parser.tab.c"
    break;

  case 34: /* BlockDecl: VarDecl  */
#line 428 "parser.y"
                   { // variable declaration

		   // ast
		   (yyval.ast) = (yyvsp[0].ast);

		}
#line 1798 "parser.tab.c"
    break;

  case 35: /* BlockDecl: StmtList  */
#line 433 "parser.y"
                             { // statement list

			// ast
			(yyval.ast) = (yyvsp[0].ast);

		}
#line 1809 "parser.tab.c"
    break;

  case 36: /* BlockDecl: WhileStmt  */
#line 438 "parser.y"
                              { // while loop

			//ast
			(yyval.ast) = (yyvsp[0].ast);
		
		}
#line 1820 "parser.tab.c"
    break;

  case 37: /* BlockDecl: IfStmt  */
#line 443 "parser.y"
                           { // if statement
			// ast
			(yyval.ast) = (yyvsp[0].ast);

}
#line 1830 "parser.tab.c"
    break;

  case 39: /* StmtList: Expr StmtList  */
#line 450 "parser.y"
                                { // nothing or recursive list of statements
				
				// ast
				(yyvsp[-1].ast)->left = (yyvsp[0].ast); 
				(yyval.ast) = (yyvsp[-1].ast);
			
			}
#line 1842 "parser.tab.c"
    break;

  case 40: /* StmtList: Expr  */
#line 456 "parser.y"
                                 { // or single expression
				
				// ast
				(yyval.ast) = (yyvsp[0].ast);
		
}
#line 1853 "parser.tab.c"
    break;

  case 41: /* VarDecl: INT ID SEMICOLON  */
#line 466 "parser.y"
                                 { printf(BOLD "RECOGNIZED RULE: (INT) Variable Declaration\n\n" RESET);	// e.g. int x;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found((yyvsp[-1].string),scope) == 1) { // if we find the variable in the symbol table
									printf(RED "\nERROR: Variable '%s' already declared.\n" RESET,(yyvsp[-1].string)); // error message
									exit(0); // exit program
								}

							// symbol table
							addItem((yyvsp[-1].string), "VAR", "INT", scope, 0); // add variable to the correct symbol table based on scope

							// ast
							(yyval.ast) = AST_assignment("TYPE",(yyvsp[-2].string),(yyvsp[-1].string)); // add variable to ast

							// ir code
							createIntDefinition((yyvsp[-1].string), scope); // create ir code: T0 = x

							// mips code 
							createMIPSIntDecl((yyvsp[-1].string),scope); // create mips: Gx: .word 0
							
							// code optimization
								// N/A

							/*
										VarDecl
									INT        ID
							*/
						}
				
			}
#line 1892 "parser.tab.c"
    break;

  case 42: /* VarDecl: ID EQ NUMBER SEMICOLON  */
#line 499 "parser.y"
                                                        { printf(BORANGE "RULE: (INT) Variable Initialization \n\n" RESET); // e.g. x = 1;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found((yyvsp[-3].string),scope) == 0) { // if we don't find the variable in the global symbol table
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
										exit(0); // exit program
									}
								} 
								else { // else the scope is function
									if (found((yyvsp[-3].string),scope) == 0) { // if we don't find the variable in the function symbol table
										if (found((yyvsp[-3].string), "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // show the symbol tables
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue((yyvsp[-3].string), scope, (yyvsp[-1].string)) == 0) { // if statement is redundant
									printf(RED "::::> CHECK FAILED: Variable %s has already been declared as: %s.\n\n" RESET,(yyvsp[-3].string),(yyvsp[-1].string)); // error message
									exit(0); // exit program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found((yyvsp[-3].string), scope) == 1) { // if the variable is found in the function's sym table

									updateValue((yyvsp[-3].string), scope, (yyvsp[-1].string)); // update value in function sym table

								} else if (found((yyvsp[-3].string), "G") == 1) { // if the variable is found in the global scope

									updateValue((yyvsp[-3].string), "G", (yyvsp[-1].string)); // update value in global sym table

								}

							} else { // if scope is global
								updateValue((yyvsp[-3].string), scope, (yyvsp[-1].string)); // update value normally
							}

							// ast
							(yyval.ast) = AST_BinaryExpression("=",(yyvsp[-3].string),(yyvsp[-1].string)); // add binary expression to the ast

							// ir code
							createIntAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create ir code: T0 = 1

							// mips code
							createMIPSIntAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create mips code for int assignment

							// code optimization
								// N/A

							/*
									=
								ID    NUMBER
							*/

						}

			}
#line 1963 "parser.tab.c"
    break;

  case 43: /* VarDecl: CHAR ID SEMICOLON  */
#line 564 "parser.y"
                                                        { printf(BORANGE "RULE: (Char) Variable Declaration \n\n" RESET); // e.g. char c;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found((yyvsp[-1].string),scope) == 1) { // if we find the variable in the symbol table
									exit(0); // variable already declared
								}

							// symbol table	
							addItem((yyvsp[-1].string), "VAR", "CHR", scope, 0); // add char variable to the symbol table

							// ast
							(yyval.ast) = AST_assignment("TYPE",(yyvsp[-2].string),(yyvsp[-1].string)); // add char variable to the ast

							// ir code
							createCharDefinition((yyvsp[-1].string), scope); // create ir code: T1 = c

							
							// code optimization
								// N/A

							/*
									VarDecl
								CHAR	   ID
							*/	

						}				
			
			}
#line 1999 "parser.tab.c"
    break;

  case 44: /* VarDecl: ID EQ CHARID SEMICOLON  */
#line 594 "parser.y"
                                                          { printf(BORANGE "RULE: (Char) Variable Initialization \n\n" RESET); // e.g. c = 'a';	

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// remove apostrophes from CHARID
							char* str = removeApostrophes((yyvsp[-1].string)); // symbol table function to return char without apostrophes

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found((yyvsp[-3].string),scope) == 0) { // if the variable is not found in the global scope
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
										exit(0); // exit program
									}
								}
								else { // else we are in function scope
									if (found((yyvsp[-3].string),scope) == 0) { // if the variable is not found in the function scope
										if (found((yyvsp[-3].string), "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // access symbol table
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue((yyvsp[-3].string), scope, str) == 0) { // if statement is redundant
									printf(RED "::::> CHECK FAILED: Variable '%s' has already been declared as: %s.\n\n" RESET,(yyvsp[-3].string),(yyvsp[-1].string)); // error message
									exit(0); // exit the program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found((yyvsp[-3].string), scope) == 1) { // if the variable is found in the function's sym table

									updateValue((yyvsp[-3].string), scope, str); // update value in function sym table

								} else if (found((yyvsp[-3].string), "G") == 1) { // if the variable is found in the global scope

									updateValue((yyvsp[-3].string), "G", str); // update value in global sym table

								}

							} else { // if scope is global
								updateValue((yyvsp[-3].string), scope, str); // update value normally
							}
							
							// ast
							(yyval.ast) = AST_BinaryExpression("=",(yyvsp[-3].string),str); // add binary expression to ast

							// ir code
							createCharAssignment((yyvsp[-3].string), str, scope); // create it code: T1 = 'a'

							// mips code
							createMIPSCharAssignment((yyvsp[-3].string), str, scope); // create mips

							// code optimization
								// N/A

							/*
									=
								ID	   CHARID
							*/

						}

			}
#line 2073 "parser.tab.c"
    break;

  case 45: /* VarDecl: FLOAT ID SEMICOLON  */
#line 662 "parser.y"
                                                { printf(BORANGE "RULE: (Float) Variable Declaration\n\n" RESET);	// e.g. float f;

						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared?
								symTabAccess(); // access symbol table
								if (found((yyvsp[-1].string),scope) == 1) { // if the variable is found in the symbol table
									printf(RED "\nERROR: Variable '%s' already declared.\n" RESET,(yyvsp[-1].string)); // error message
									exit(0); // exit program
								}

							// symbol table
							addItem((yyvsp[-1].string), "VAR", "FLT", scope, 0); // add the float variable to the symbol table

							// ast
							(yyval.ast) = AST_assignment("TYPE",(yyvsp[-2].string),(yyvsp[-1].string)); // add the float variable to the ast

							// ir code
							createFloatDefinition((yyvsp[-1].string), scope); // create ir code: T2 = f

							// mips code
							
							// code optimization
								// N/A

							/*
										VarDecl
									INT        ID
							*/

						}

				}
#line 2112 "parser.tab.c"
    break;

  case 46: /* VarDecl: ID EQ FLOATNUM SEMICOLON  */
#line 695 "parser.y"
                                                                        { printf(BORANGE "RULE: (Float) Variable Initialization \n\n" RESET); // e.g. f = 1.0;
							
						if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

							// semantic checks
								// is the variable already declared
								symTabAccess(); // access symbol table
								if (scope == "G") { // if the scope is global
									if (found((yyvsp[-3].string),scope) == 0) { // if the variable is not found in the global scope
										printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
										exit(0); // exit program
									}
								} 
								else { // else the scope is function
									if (found((yyvsp[-3].string),scope) == 0) { // if the variable is not found in the function scope
										if (found((yyvsp[-3].string), "G") == 0) { // if the variable is not found in the global scope
											showSymTable(); // show the symbol table
											printf(RED "\n::::> CHECK FAILED: Variable '%s' not initialized in the function or global scope.\n\n" RESET,(yyvsp[-3].string)); // error message
											exit(0); // exit program
										}
									}
								}

								// is the statement redundant
								if (redundantValue((yyvsp[-3].string), scope, (yyvsp[-1].string)) == 0) { // if statement is redundant
									printf(RED "\n::::> CHECK FAILED: Variable '%s' has already been declared as: %s.\n\n" RESET,(yyvsp[-3].string),(yyvsp[-1].string)); // error message
									exit(0); // exit program
								}

							// symbol table
							if (strcmp(scope, "G") != 0) { // if scope is in function

								if (found((yyvsp[-3].string), scope) == 1) { // if the variable is found in the function's sym table

									updateValue((yyvsp[-3].string), scope, (yyvsp[-1].string)); // update value in function sym table

								} else if (found((yyvsp[-3].string), "G") == 1) { // if the variable is found in the global scope

									updateValue((yyvsp[-3].string), "G", (yyvsp[-1].string)); // update value in global sym table

								}

							} else { // if scope is global
								updateValue((yyvsp[-3].string), scope, (yyvsp[-1].string)); // update value normally
							}

							// ast
							(yyval.ast) = AST_BinaryExpression("=",(yyvsp[-3].string),(yyvsp[-1].string)); // add float variable to ast

							// ir code
							createFloatAssignment((yyvsp[-3].string),(yyvsp[-1].string), scope); // create ir code: T3 = 1.0

							// mips code
							createMIPSFloatAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create mips

							// code optimization
								// N/A

							/*
									=
								ID    NUMBER
							*/

						}

				}
#line 2183 "parser.tab.c"
    break;

  case 47: /* VarDecl: ID EQ ID SEMICOLON  */
#line 760 "parser.y"
                                                                { printf(BORANGE "RULE: Assignment Statement\n\n" RESET); // e.g. x = y;

					if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

						// semantic checks
							// are both variables already declared?
							symTabAccess(); // access symbol table
							printf("\n"); // print newline
							if (found((yyvsp[-3].string),scope) == 0 || found((yyvsp[-1].string),scope) == 0) { // if both variables are not found in the scope
								printf(RED "\nERROR: Variable %s or %s not declared.\n\n" RESET,(yyvsp[-3].string),(yyvsp[-1].string)); // error message
								exit(0); // exit program
							}

							// does the second id have a value?
							//initialized($3, scope);

							// are the id's both variables?
							//compareKinds($1, $3, scope);

							// are the types of the id's the same
							compareTypes((yyvsp[-3].string), (yyvsp[-1].string), scope);

						// symbol table
						updateValue((yyvsp[-3].string), scope, getValue((yyvsp[-1].string), scope)); // update the value of the first id in the symbol table

						// ast
						(yyval.ast) = AST_BinaryExpression("=",(yyvsp[-3].string),(yyvsp[-1].string)); // add expression to the ast

						// ir code
						createIDtoIDAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create ir code: T0 = T1

						// mips code
						createMIPSIDtoIDAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create mips

						// code optimization
							// mark the two id's as used
							isUsed((yyvsp[-3].string), scope);
							isUsed((yyvsp[-1].string), scope);

					}


				}
#line 2231 "parser.tab.c"
    break;

  case 48: /* VarDecl: IDEQExpr SEMICOLON  */
#line 802 "parser.y"
                                                       { printf(BORANGE "RULE: ADD Statement\n\n" RESET); // id = math statement, e.g. x = 10 - 8;

					if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

						// ast
						(yyval.ast) = (yyvsp[-1].ast);

					}

				}
#line 2246 "parser.tab.c"
    break;

  case 49: /* VarDecl: ArrDecl  */
#line 811 "parser.y"
                                            { // array declaration

}
#line 2254 "parser.tab.c"
    break;

  case 50: /* Expr: SEMICOLON  */
#line 826 "parser.y"
                  {  // just a semicolon

	}
#line 2262 "parser.tab.c"
    break;

  case 51: /* Expr: ID EQ ID SEMICOLON  */
#line 828 "parser.y"
                                   { printf(BORANGE "RULE: Assignment Statement\n\n" RESET); // e.g. x = y like above, but can also be present in a stmtList

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// are both variables already declared?
				symTabAccess(); // access symbole table
				printf("\n"); // print newline
				if (found((yyvsp[-3].string),scope) == 0 || found((yyvsp[-1].string),scope) == 0) { // if both variables are not found in the scope
					printf(RED "\nERROR: Variable %s or %s not declared.\n\n" RESET,(yyvsp[-3].string),(yyvsp[-1].string)); // error message
					exit(0); // exit progrma
				}

				// does the second id have a value?
				initialized((yyvsp[-1].string), scope);

				// are the id's both variables?
				compareKinds((yyvsp[-3].string), (yyvsp[-1].string), scope);

				// are the types of the id's the same
				compareTypes((yyvsp[-3].string), (yyvsp[-1].string), scope);

			// symbol table
			updateValue((yyvsp[-3].string), scope, getValue((yyvsp[-1].string), scope)); // update value of first id in symbol table

			// ast
			(yyval.ast) = AST_BinaryExpression("=",(yyvsp[-3].string),(yyvsp[-1].string)); // add expression to the ast

			// ir code
			createIDtoIDAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create ir code: T0 = T1

			// mips code
			createMIPSIDtoIDAssignment((yyvsp[-3].string), (yyvsp[-1].string), scope); // create mips

			// code optimization
				// mark the two id's as used
				isUsed((yyvsp[-3].string), scope);
				isUsed((yyvsp[-1].string), scope);

		}

	}
#line 2309 "parser.tab.c"
    break;

  case 52: /* Expr: ID EQ ID LPAREN ArgDeclList RPAREN SEMICOLON  */
#line 869 "parser.y"
                                                         { printf(BORANGE "RULE: ID = Function\n" RESET); // e.g. x = addValue(1,2);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// set scope to function
			strcpy(scope, (yyvsp[-4].string));

			// loop through arguments and do parser functions
			for (int i = 0; i < argCounter; i++) { // from 0 to however many arguments there are

				printf(BGREEN "IF Parameter Accepted\n" RESET); // output to console

				// ir code
				printf(BLUE "IR Code" RESET);
				printf(RED " NOT " RESET);
				printf(BLUE "Created\n" RESET); // ir code not yet created

				// variables for getting parameter name based on index
				char itemName[50]; // stores name of parameter
				char itemID[50]; // stores id of the parameter
				char result[50]; // stores the result of below function

				// get parameter name based on index of for loop
				sprintf(itemID, "%d", i); // convert i into a string
				sprintf(itemName, "%s", getNameByID(itemID, scope)); // add the name of the parameter into itemName
				strcpy(result, ""); // redundant
				strcat(result, itemName); // store itemName in result

				// variables to hold the type of the parameter
				char type[50];
				int isInt, isFloat, isChar;

				// get the type of the parameter
				sprintf(type, "%s", getVariableType(itemName, scope));
				
				// determine whether the type is INT, FLT, or CHR
				isInt = strcmp(type, "INT"); // compare type to "INT"
				isFloat = strcmp(type, "FLT"); // compare type to "FLT"
				isChar = strcmp(type, "CHR"); // compare type to "CHR"

				if (isInt == 0) { // if the parameter is an integer
					if (argIsID == 1) { // if parameter is an ID

						// mips
						createIntIDParameter(IDArg, i+1, "G"); // create mips for an id parameter
						argIsID = 0; // revert argIsID to 0 (it gets set to 1 when it sees an ID parameter in ArgDeclList)

					} 
					else { // if parameter is an integer

						// mips
						createIntParameter(args[i], i+1, scope); // create mips for an integer parameter

					}
				} else if (isFloat == 0) { // if parameter is a float

					// mips
					createFloatParameter(args[i], i+1, scope); // create mips for a float parameter
	
				} else if (isChar == 0) { // if parameter is a char

					// mips
					createMIPSCharAssignment(result, args[i], scope); // create mips for a char parameter

				}
				
			}
			argCounter = 0; // revert argCounter to 0 (it gets incremented when counting arguments in ArgDeclList)

			// set scope back to global
			strcpy(scope, "G");

			// symbol table
			printf(BGREEN "Function Call --- Parameters Accepted\n" RESET); // output to console

			// mips again
			callMIPSFunction((yyvsp[-4].string)); // create mips for the calling of a function
			setVariableToReturn((yyvsp[-6].string), (yyvsp[-4].string), scope); // update the variable for the return type of this function

		}

	}
#line 2396 "parser.tab.c"
    break;

  case 53: /* Expr: WRITE ID SEMICOLON  */
#line 950 "parser.y"
                                   { printf(BORANGE "RULE: Write Statement (Var)\n" RESET); // e.g. write x;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// is the id initialized as a value?
				initialized((yyvsp[-1].string), scope); // symbol table function: exits if not initialized
			
			// symbol table
				// N/A

			// ast
			(yyval.ast) = AST_BinaryExpression("Expr", (yyvsp[-2].string), getValue((yyvsp[-1].string), scope)); // add the write statement to the ast

			// ir code
			createWriteId((yyvsp[-1].string), scope); // create ir code: output T0

			// mips
			// get the type of the variable
			char* type = getVariableType((yyvsp[-1].string), scope);

			// determine if its int or char
			int isInt = strcmp(type, "INT"); // compare type to "INT"
			int isChar = strcmp(type, "CHR"); // compare type to "CHR"
			int isFloat = strcmp(type, "FLT"); // compare type to "FLT"

			// run correct mips function according to type
			if (isInt == 0) { // if the variable is an integer
				createMIPSWriteInt((yyvsp[-1].string), scope); // create mips
			} 
			else if (isChar == 0) { // if the variable is a char
				createMIPSWriteChar((yyvsp[-1].string), scope); // create mips
			} 
			else if (isFloat == 0) { // if the variable is a float
				createMIPSWriteFloat((yyvsp[-1].string), scope); // create mips
			}

			// code optimization
				// mark the id as used
				isUsed((yyvsp[-1].string), scope);

			/*
						Expr
				WRITE     getValue(ID)
			*/
		}

	}
#line 2449 "parser.tab.c"
    break;

  case 54: /* Expr: WRITE STRINGID SEMICOLON  */
#line 997 "parser.y"
                                         { printf(BORANGE "RULE: Write Statement (String)\n" RESET); // e.g. write "Hello World!";

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// semantic checks
				// N/A

			// symbol table
				// N/A

			// ast
			(yyval.ast) = AST_BinaryExpression("Expr", (yyvsp[-2].string), (yyvsp[-1].string)); // add expression to the ast

			// ir code
			char str[50]; // variable to hold string without apostrophes
			strcpy(str, removeApostrophes((yyvsp[-1].string))); // remove apostrophes and copy string into str
			createWriteString(str); // create ir code: output "Hello World!""

			// mips code
			defineMIPSTempString(str); // create mips temp definition at the top of the file to hold the string
			createMIPSWriteString((yyvsp[-1].string), scope); // create mips code to display the string in scope

			// code optimization
				// mark the id as used
				isUsed((yyvsp[-1].string), scope);

		}

	}
#line 2483 "parser.tab.c"
    break;

  case 55: /* Expr: WRITE ID LBRACE NUMBER RBRACE SEMICOLON  */
#line 1025 "parser.y"
                                                        { printf(BORANGE "RULE: Write Statement (Array)\n" RESET); // e.g. write arr[0];

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// concatenate the array in this format: "$2[$4]"
			char elementID[50]; // holds the id of the element in the array
			strcpy(elementID, (yyvsp[-4].string)); // elementID: arr
			strcat(elementID, "["); // elementID: arr[
			strcat(elementID, (yyvsp[-2].string)); // elementID: arr[0
			strcat(elementID, "]"); // elementID: arr[0]

			// semantic checks
				// is the id initialized as a value?
				initialized(elementID, scope); // symbol table function: exits if not initialized
				
			// symbol table
				// N/A

			// ast
			(yyval.ast) = AST_BinaryExpression("Expr", (yyvsp[-5].string), getValue(elementID, scope)); // add expression to ast

			// ir code
			createWriteId(elementID, scope); // create ir code: T0 = arr[0]

			// mips code
				// get the type of the element
				char* type = getVariableType(elementID, scope); // symbol table function that returns type

				// determine if its int or char
				int isInt = strcmp(type, "INT"); // compare type to "INT"
				int isChar = strcmp(type, "CHR"); // compare type to "CHR"
				int isFloat = strcmp(type, "FLT"); // compare type to "FLT"

				// run correct mips function according to type
				if (isInt == 0) { // if the elemnt is an integer
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteInt(elementID, scope); // create mips to write the element
				} 
				else if (isChar == 0) { // if the element is a char
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteChar(elementID, scope); // create mips to write the element
				} 
				else if (isFloat == 0) { // if the element is a float
					removeBraces(elementID); // remove the braces to make its name in mips
					createMIPSWriteFloat(elementID, scope); // create mips to write the element
				}

			// code optimization
				// mark the id as used
				isUsed((yyvsp[-4].string), scope);

		}

	}
#line 2542 "parser.tab.c"
    break;

  case 56: /* Expr: WRITE NEWLINECHAR SEMICOLON  */
#line 1078 "parser.y"
                                        { printf(BORANGE "RULE: New Line\n\n" RESET); // e.g. write ~nl;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// ast
			(yyval.ast) = AST_BinaryExpression("Expr", (yyvsp[-2].string), "NEWLINE"); // add newline expression to ast

			// ir code
			createNewLine(); // create ir code: output *newline*

			// mips
			makeMIPSNewLine(scope); // create newline in mips

		}

	}
#line 2563 "parser.tab.c"
    break;

  case 57: /* Expr: IDEQExpr SEMICOLON  */
#line 1093 "parser.y"
                               { printf(BORANGE "RULE: Math Statement\n\n" RESET); // e.g. x = 3 - 1; same as above, just can also be in a stmtList

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// ast
			(yyval.ast) = (yyvsp[-1].ast);

		}

	}
#line 2578 "parser.tab.c"
    break;

  case 58: /* Expr: ID LBRACE NUMBER RBRACE EQ NUMBER SEMICOLON  */
#line 1102 "parser.y"
                                                        { printf(BORANGE "RULE: Integer Array Index\n\n" RESET); // e.g. arr[0] = 1;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// add backets to id
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",(yyvsp[-6].string),(yyvsp[-4].string)); // fills temp with: arr[0] for example

			// convert index to integer
			int index = atoi((yyvsp[-4].string)); // stores converted integer in index variable

			// symbol table
			updateArrayValue((yyvsp[-6].string), index, scope, "INT", (yyvsp[-1].string)); // update value of the array element in the symbol table

			// symbol table
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					updateArrayValue((yyvsp[-6].string), index, scope, "INT", (yyvsp[-1].string)); // update value in function sym table

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					updateArrayValue((yyvsp[-6].string), index, "G", "INT", (yyvsp[-1].string)); // update value in global sym table

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				updateArrayValue((yyvsp[-6].string), index, scope, "INT", (yyvsp[-1].string)); // update value normally
			}

			// ast
			(yyval.ast) = AST_assignment((yyvsp[-6].string),(yyvsp[-4].string),(yyvsp[-1].string)); // add expression to the ast

			// ir code
			createIntAssignment(temp, (yyvsp[-1].string), scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, (yyvsp[-1].string), scope); // create mips to update the array element

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, (yyvsp[-1].string), "G"); // create mips to update the array element

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} 
			else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSIntAssignment(temp, (yyvsp[-1].string), scope); // create mips to update the array element
			}

		}

	}
#line 2656 "parser.tab.c"
    break;

  case 59: /* Expr: ID LBRACE NUMBER RBRACE EQ Math SEMICOLON  */
#line 1174 "parser.y"
                                                      { printf(BORANGE "RULE: Integer Array Index (Math)\n\n" RESET); // e.g. arr[0] = 1 + 2;

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			system("python3 calculate.py"); // perform calculation
	
			char result[100]; // store result of calculation
			readEvalOutput(&result); // read the output and store in result
			clearCalcInput(); // clear the input to the calculator
			printf(RED"\nResult from evaluation ==> %s \n"RESET,result); // output result to console
	
			// convert index to integer
			int index = atoi((yyvsp[-4].string)); // convert index to integer and store in index variable

			// symbol table
			updateArrayValue((yyvsp[-6].string), index, scope, "INT", result); // update array element in symbol table

			// ast
			(yyval.ast) = AST_assignment((yyvsp[-6].string),(yyvsp[-4].string),result); // add expression to symbol table

			// ir code
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",(yyvsp[-6].string),(yyvsp[-4].string)); // fills temp with: arr[0] for example
			createIntAssignment(temp, result, scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is in function
				if (found(temp, scope) == 1) { // if the variable is found in the function scope
					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, result, scope); // create mips to update the array element
				} 
				else if (found(temp, "G") == 1) { // if the variable is found in the global scope
					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSIntAssignment(temp, result, "G"); // create mips to update the array element
				} 
				else { // variable not found
					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program
				}
			} else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSIntAssignment(temp, result, scope); // create mips to update the array element
			}
		}
	
	}
#line 2708 "parser.tab.c"
    break;

  case 60: /* Expr: ID LBRACE NUMBER RBRACE EQ CHARID SEMICOLON  */
#line 1220 "parser.y"
                                                        { printf(BORANGE "RULE: Char Array Index\n\n" RESET); // e.g. arr[0] = 'c';

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// add brackets to id for sym table searches
			char temp[50]; // temp variable to hold id with brackets
			sprintf(temp,"%s[%s]",(yyvsp[-6].string),(yyvsp[-4].string)); // fills temp with: arr[0] for example

			// convert index to integer
			int index = atoi((yyvsp[-4].string)); // store converted array index in index variable

			// remove apostrophes from CHARID
			char* str = removeApostrophes((yyvsp[-1].string)); // remove apostrophes function from symbol table

			// symbol table
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					updateArrayValue((yyvsp[-6].string), index, scope, "CHR", str); // update value in function sym table

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					updateArrayValue((yyvsp[-6].string), index, "G", "CHR", str); // update value in global sym table

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				updateArrayValue((yyvsp[-6].string), index, scope, "CHR", str); // update value normally
			}

			// ast
			(yyval.ast) = AST_assignment((yyvsp[-6].string),(yyvsp[-4].string),str); // add expression to the ast

			// ir code
			createIntAssignment(temp, str, scope); // create ir code

			// mips code
			if (strcmp(scope, "G") != 0) { // if scope is in function

				if (found(temp, scope) == 1) { // if the variable is found in the function's sym table

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSCharAssignment(temp, str, scope); // create mips to update the array element

				} else if (found(temp, "G") == 1) { // if the variable is found in the global scope

					removeBraces(temp); // remove the braces to make its name in mips
					createMIPSCharAssignment(temp, str, "G"); // create mips to update the array element

				} else { // variable not found

					showSymTable(); // show symbol table
					printf(RED "\nERROR: Variable '%s' does not exist.\n\n" RESET, temp); // error message
					exit(0); // exit program

				}

			} else { // if scope is global
				removeBraces(temp); // remove the braces to make its name in mips
				createMIPSCharAssignment(temp, str, scope); // create mips to update the array element
			}
		}

	}
#line 2784 "parser.tab.c"
    break;

  case 61: /* Expr: ID LPAREN ArgDeclList RPAREN SEMICOLON  */
#line 1290 "parser.y"
                                                   { printf(BORANGE "RULE: Call Function\n\n" RESET); // e.g. addValue(1,2);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// set scope to function
			strcpy(scope, (yyvsp[-4].string));

			// loop through arguments
			for (int i = 0; i < argCounter; i++) {

				printf(BGREEN "IF Parameter Accepted\n" RESET); // output to console

				// ir code
				printf(BLUE "IR Code" RESET);
				printf(RED " NOT " RESET);
				printf(BLUE "Created\n" RESET); // ir code not yet created

				// variables for getting parameter name based on index
				char itemName[50]; // stores name of parameter
				char itemID[50]; // stores id of the parameter
				char result[50]; // stores the result of below function

				// get parameter name based on index of for loop
				sprintf(itemID, "%d", i); // convert i into a string
				sprintf(itemName, "%s", getNameByID(itemID, scope)); // add the name of the parameter into itemName
				strcpy(result, ""); // redundant
				strcat(result, itemName); // store itemName in result

				// variables to hold the type of the parameter
				char type[50];
				int isInt, isFloat, isChar;

				// get the type of the parameter
				sprintf(type, "%s", getVariableType(itemName, scope));
				
				// get type of parameter
				isInt = strcmp(type, "INT"); // compare type to "INT"
				isFloat = strcmp(type, "FLT"); // compare type to "FLT"
				isChar = strcmp(type, "CHR"); // compare type to "CHR"

				// run mips based on type
				if (isInt == 0) { // if parameter is an integer
					if (argIsID == 1) { // if parameter is an ID
						createIntIDParameter(IDArg, i+1, scope); // create integer ID parameter in mips
						argIsID = 0; // reset argIsID to 0 (gets changed to 1 in argDeclList)
					} 
					else { // if parameter is an integer number
						createIntParameter(args[i], i+1, scope); // create integer parameter in mips
					}
				} 
				else if (isFloat == 0) { // if parameter is a float
					createFloatParameter(args[i], i+1, scope); // create float parameter in mips
				} 
				else if (isChar == 0) { // if parameter is a char
					createMIPSCharAssignment(result, args[i], scope); // create char parameter in mips
				}
			}
			argCounter = 0; // reset argCounter to 0 (gets set to 1 when counting arguments in argDeclList)

			// set scope back to global
			strcpy(scope, "G");

			// symbol table
			printf(BGREEN "Function Call --- Parameters Accepted\n" RESET); // output to console

			// ast
			(yyval.ast) = AST_assignment((yyvsp[-4].string),(yyvsp[-3].string),(yyvsp[-1].string)); // add expression to the ast

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET); // ir code currently not needed

			// mips
			callMIPSFunction((yyvsp[-4].string)); // create function call in mips

		}

	}
#line 2868 "parser.tab.c"
    break;

  case 62: /* Expr: RETURN ID SEMICOLON  */
#line 1368 "parser.y"
                                { printf(BORANGE "RULE: Return Statement (ID)\n\n" RESET); // e.g. return x; (inside a function)

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0

			// symbol table
			updateValue(scope, "G", getValue((yyvsp[-1].string), scope)); // update the value of the function in the global table
			printf(BGREEN "Updated ID Return Value of Function.\n" RESET); // output to console

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET); // ir code not currently needed

			// temp variables
			char str[50]; // temp string to hold variable type
			strcpy(str, getVariableType((yyvsp[-1].string), scope)); // store variable type in 'str'

			char str1[50]; // temp string to hold "G{scope}"
			strcpy(str1, "G"); // store "G" in 'str1'
			strcat(str1, scope); // concatenate the scope to 'str1'

			char str2[50]; // temp string to hold "{scope}Return" for function return variable in mips
			strcpy(str2, scope); // store scope in 'str2'
			strcat(str2, "Return"); // concatenate "Return" to 'str2'
			
			// mips based on type
			if (strcmp(str, "INT") == 0) { // if the id is an integer

				// ir code
				createReturnIDStatement((yyvsp[-1].string)); // create ir code: return T2

				// mips
				createMIPSReturnStatementNumber(str2, (yyvsp[-1].string), getValue((yyvsp[-1].string), scope), scope); // create mips return variable

			} 
			else if (strcmp(str, "FLT") == 0) { // if the id is a float

				// ir code
				createReturnIDStatement((yyvsp[-1].string)); // create ir code: return T2

				// mips
				createMIPSFloatAssignment("", getValue((yyvsp[-1].string), scope), str1); // create mips return variable

			} 
			else if (strcmp(str, "CHR") == 0) { // if the id is char

				// ir code
				createReturnIDStatement((yyvsp[-1].string)); // create ir code: return T2

				// mips
				createMIPSCharAssignment("", getValue((yyvsp[-1].string), scope), str1); // create mips return variable
			}
			
		}

	}
#line 2929 "parser.tab.c"
    break;

  case 63: /* Expr: RETURN NUMBER SEMICOLON  */
#line 1423 "parser.y"
                                    { printf(BORANGE "RULE: Return Statement (INT)\n\n" RESET);

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", (yyvsp[-1].string));
			printf(BGREEN "Updated Integer Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			// create scope so that it has G and then the function scope, since
			// we are accessing the global variable that is called the function name
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);

			createMIPSIntAssignment("", (yyvsp[-1].string), str);
		}

	}
#line 2957 "parser.tab.c"
    break;

  case 64: /* Expr: RETURN FLOATNUM SEMICOLON  */
#line 1445 "parser.y"
                                      {

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", (yyvsp[-1].string));
			printf(BGREEN "Updated Float Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			// create scope so that it has G and then the function scope, since
			// we are accessing the global variable that is called the function name
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);

			createMIPSFloatAssignment("", (yyvsp[-1].string), str);
		}

	}
#line 2985 "parser.tab.c"
    break;

  case 65: /* Expr: RETURN CHARID SEMICOLON  */
#line 1467 "parser.y"
                                    {

		if (ifElseCurrentBlock == runIfElseBlock) { // if we are in an if block, both are 1, if we are in an else block, both are 0
			// symbol table
			updateValue(scope, "G", (yyvsp[-1].string));
			printf(BGREEN "Updated Char Return Value of Function.\n" RESET);

			// ir code
			printf(BLUE "IR Code" RESET);
			printf(RED " NOT " RESET);
			printf(BLUE "Created\n" RESET);

			// mips
			char str[50];
			strcpy(str, "G");
			strcat(str, scope);
			createMIPSCharAssignment("", (yyvsp[-1].string), str);
		}

}
#line 3010 "parser.tab.c"
    break;

  case 66: /* IDEQExpr: ID EQ MathStmt  */
#line 1492 "parser.y"
                         {

	// ast
	// TODO: EVAN
	if (scope == "G" && inElseOrWhile != UPDATE_WHILE) { // ADD CHECK HERE FOR IF NOT IN WHILE LOOP, IF IN WHILE LOOP, NEED TO DO ELSE

		system("python3 calculate.py");
		
		char result[100];
		readEvalOutput(&result);
		clearCalcInput();
		printf(RED"\nResult from evaluation ==> %s \n"RESET,result);

		// semantic checks
			// inside Math

		// calculations: code optimization
			// turn the integer returned from calculate() into a string

		// symbol table

		if (strcmp(scope, "G") != 0) { // if scope is in function

			if (found((yyvsp[-2].string), scope) == 1) { // if the variable is found in the function's sym table

				updateValue((yyvsp[-2].string), scope, result); // update value in function sym table

			} else if (found((yyvsp[-2].string), "G") == 1) { // if the variable is found in the global scope

				updateValue((yyvsp[-2].string), "G", result); // update value in global sym table

			}

		} else { // if scope is global
			updateValue((yyvsp[-2].string), scope, result); // update value normally
		}

		// ast
		(yyval.ast) = AST_BinaryExpression("=", (yyvsp[-2].string), result);

		
		char type[50];

		strcpy(type,getVariableType((yyvsp[-2].string),scope));

		if (strcmp(type,"INT") == 0){
			// ir code
			createIntAssignment((yyvsp[-2].string), result, scope);

			// mips code
			createMIPSIntAssignment((yyvsp[-2].string), result, scope);
		}

		else if(strcmp(type,"FLT") == 0){
			// ir code
			createFloatAssignment((yyvsp[-2].string), result, scope);

			// mips code
			createMIPSFloatAssignment((yyvsp[-2].string), result, scope);
		}

		
		// code optimization
		// mark the id as used
		isUsed((yyvsp[-2].string), scope);

	} else {

		if (scope != "G" && inElseOrWhile != UPDATE_WHILE) { // in a function

			if (op == '+') {

				// ir code
				createFunctionAddition((yyvsp[-2].string));

				// mips
				createMIPSParameterAddition((yyvsp[-2].string), scope);

			} else if (op == '-') {

				// ir code
				createFunctionSubtraction((yyvsp[-2].string));

				// mips
				createMIPSSubtraction((yyvsp[-2].string), num1, num2, scope);
			}
		
		} else { // in a while loop

			if (op == '+') {

				// ir code
				createFunctionAddition((yyvsp[-2].string));

				// mips
				createMIPSLoopAddition(scope);
			} else if (op == '-') {

				// ir code
				createFunctionSubtraction((yyvsp[-2].string));

				// mips
				createMIPSLoopSubtraction(scope);
			}

		}

	}

}
#line 3125 "parser.tab.c"
    break;

  case 67: /* MathStmt: Math MathStmt  */
#line 1603 "parser.y"
                        {

}
#line 3133 "parser.tab.c"
    break;

  case 68: /* MathStmt: Math  */
#line 1607 "parser.y"
                       {

}
#line 3141 "parser.tab.c"
    break;

  case 69: /* Math: LPAREN  */
#line 1612 "parser.y"
             {addToInputCalc((yyvsp[0].string));}
#line 3147 "parser.tab.c"
    break;

  case 70: /* Math: RPAREN  */
#line 1613 "parser.y"
                         {addToInputCalc((yyvsp[0].string));}
#line 3153 "parser.tab.c"
    break;

  case 71: /* Math: ID  */
#line 1614 "parser.y"
                     {
			addToInputCalc(getValue((yyvsp[0].string),scope)); 
			strcpy(num1, (yyvsp[0].string));

			//printf(BORANGE "inElseOrWhile: %s\nUPDATE_WHILE: %d\n", inElseOrWhile, UPDATE_WHILE);
			
			if (inElseOrWhile == UPDATE_WHILE) {

				createMIPSAddIDToRegister((yyvsp[0].string), registerCounter, scope);
				registerCounter++;
				
			}


		}
#line 3173 "parser.tab.c"
    break;

  case 72: /* Math: NUMBER  */
#line 1630 "parser.y"
                         {
			addToInputCalc((yyvsp[0].string)); 
			strcpy(num2, (yyvsp[0].string)); 

			if (inElseOrWhile == UPDATE_WHILE) {

				createMIPSAddNumberToRegister((yyvsp[0].string), registerCounter);
				registerCounter++;

			}
		
		}
#line 3190 "parser.tab.c"
    break;

  case 73: /* Math: FLOATNUM  */
#line 1642 "parser.y"
                           {addToInputCalc((yyvsp[0].string));}
#line 3196 "parser.tab.c"
    break;

  case 74: /* Math: EXPONENT  */
#line 1643 "parser.y"
                           {addToInputCalc("**");}
#line 3202 "parser.tab.c"
    break;

  case 75: /* Math: Operator  */
#line 1644 "parser.y"
                           {addToInputCalc((yyvsp[0].ast));}
#line 3208 "parser.tab.c"
    break;

  case 76: /* Operator: ADD  */
#line 1648 "parser.y"
              {op = '+';}
#line 3214 "parser.tab.c"
    break;

  case 77: /* Operator: SUB  */
#line 1649 "parser.y"
                      {op = '-';}
#line 3220 "parser.tab.c"
    break;

  case 78: /* Operator: MULTIPLY  */
#line 1650 "parser.y"
                           {op = '*';}
#line 3226 "parser.tab.c"
    break;

  case 79: /* Operator: DIV  */
#line 1651 "parser.y"
                      {op = '/';}
#line 3232 "parser.tab.c"
    break;

  case 80: /* CompOperator: DEQ  */
#line 1654 "parser.y"
                  {}
#line 3238 "parser.tab.c"
    break;

  case 81: /* CompOperator: LT  */
#line 1655 "parser.y"
                             {}
#line 3244 "parser.tab.c"
    break;

  case 82: /* CompOperator: GT  */
#line 1656 "parser.y"
                             {}
#line 3250 "parser.tab.c"
    break;

  case 83: /* CompOperator: LEQ  */
#line 1657 "parser.y"
                              {}
#line 3256 "parser.tab.c"
    break;

  case 84: /* CompOperator: GEQ  */
#line 1658 "parser.y"
                              {}
#line 3262 "parser.tab.c"
    break;

  case 85: /* CompOperator: NOTEQ  */
#line 1659 "parser.y"
                                {}
#line 3268 "parser.tab.c"
    break;

  case 86: /* ArrDecl: INT ID LBRACE RBRACE SEMICOLON  */
#line 1663 "parser.y"
                                                       { printf(BORANGE "RULE: Integer Array Initialization\n\n" RESET);
				//int foo[]; //We should only have arrays be declared with range imo.



			}
#line 3279 "parser.tab.c"
    break;

  case 87: /* ArrDecl: CHAR ID LBRACE RBRACE SEMICOLON  */
#line 1668 "parser.y"
                                                            { printf(BORANGE "RULE: Char Array Initialization\n\n" RESET);
				//char foo[]; //We should only have arrays be declared with range imo.

			

			}
#line 3290 "parser.tab.c"
    break;

  case 88: /* ArrDecl: INT ID LBRACE NUMBER RBRACE SEMICOLON  */
#line 1673 "parser.y"
                                                                  { printf(BORANGE "RULE: Integer Array Initialization\n\n" RESET);
				// e.g. int foo[4];

						if (ifElseCurrentBlock == runIfElseBlock) {
							// semantic checks
							symTabAccess();

								// is the range > 0?
								if (atoi((yyvsp[-2].string)) <= 0) {
									printf(RED "\nERROR: Array range must be greater than 0.\n" RESET,(yyvsp[-4].string));
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}

								// is the array already declared in this scope?			
								// add "[0]" to the ID
								char temp[50];	
								sprintf(temp,"%s[0]",(yyvsp[-4].string));

								if (found(temp, scope) == 1) {
									printf(RED "\nERROR: Array '%s' already declared in this scope.\n" RESET,(yyvsp[-4].string));
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}

							// symbol table
							addArray((yyvsp[-4].string), "ARR", "INT", (yyvsp[-2].string), scope);

							// ast
							(yyval.ast) = AST_assignment("ARR",(yyvsp[-5].string),(yyvsp[-4].string));

							// ir code
							int range = atoi((yyvsp[-2].string));
							//printf("\n%d\n", range);
							for (int i = 0; i < range; i++) {
								char temp[50];	
								sprintf(temp,"%s[%d]",(yyvsp[-4].string),i);
								createIntDefinition(temp, scope);
							}
							printf("\n\n");
						}

			}
#line 3338 "parser.tab.c"
    break;

  case 89: /* ArrDecl: CHAR ID LBRACE NUMBER RBRACE SEMICOLON  */
#line 1715 "parser.y"
                                                                   { printf(BORANGE "RULE: Char Array Initialization\n\n" RESET);
				// e.g. char foo[5];
	
						if (ifElseCurrentBlock == runIfElseBlock) {
							// semantic checks
							symTabAccess();

								// is the range > 0?
								if (atoi((yyvsp[-2].string)) <= 0) {
									printf(RED "\nERROR: Array range must be greater than 0.\n" RESET,(yyvsp[-4].string));
									showSymTable(); // show symbol table
									exit(0); // array already declared
								}
								// is the array already declared?
								// add "[0]" to the ID
								char temp[50];	
								sprintf(temp,"%s[0]",(yyvsp[-4].string));
								
								if (found(temp, scope) == 1) {
									printf(RED "\nERROR: Array '%s' already declared in this scope.\n" RESET,(yyvsp[-4].string));
									showSymTable();
									exit(0); // variable already declared
								}

							// symbol table
							addArray((yyvsp[-4].string), "ARR", "CHR", (yyvsp[-2].string), scope);

							// ast
							(yyval.ast) = AST_assignment("ARR",(yyvsp[-5].string),(yyvsp[-4].string));

							// ir code
							int range = atoi((yyvsp[-2].string));
							//printf("\n%d\n", range);
							for (int i = 0; i < range; i++) {
								sprintf(temp,"%s[%d]",(yyvsp[-4].string),i);
								createIntDefinition(temp, scope);
							}
							printf("\n\n");
						}

}
#line 3384 "parser.tab.c"
    break;

  case 90: /* $@5: %empty  */
#line 1757 "parser.y"
                      { inElseOrWhile = UPDATE_WHILE;
					
					sprintf(whileName, "whileLoop%d",numOfWhileLoops);
					createMIPSFunction(whileName);  //create while loop function in MIPS
					callMIPSLoop(whileName);
					numOfWhileLoops++;
					changeIRFile(IR_FUNC);
					changeMIPSFile(MIPS_FUNC); //add block code to while loop function 

					// ir code
					createWhileStatement(numOfWhileLoops-1);

						}
#line 3402 "parser.tab.c"
    break;

  case 91: /* $@6: %empty  */
#line 1769 "parser.y"
                                                                          { printf(BORANGE "RULE: While Statement Initialization \n\n" RESET);							 
						 
						 }
#line 3410 "parser.tab.c"
    break;

  case 92: /* WhileStmt: WHILE $@5 LPAREN Condition RPAREN $@6 Block  */
#line 1771 "parser.y"
                                                         { 
							
							printf(BORANGE "\nRULE: While Statement Block\n\n" RESET);
							MIPSWhileJump(whileName);
							changeIRFile(IR_CODE);
							changeMIPSFile(TEMP_MIPS);

}
#line 3423 "parser.tab.c"
    break;

  case 93: /* $@7: %empty  */
#line 1780 "parser.y"
           {inElseOrWhile = UPDATE_IF_ELSE;}
#line 3429 "parser.tab.c"
    break;

  case 94: /* $@8: %empty  */
#line 1780 "parser.y"
                                                                     { printf(BORANGE "RULE: If-Else Statement Initialization \n\n" RESET);
						
						inElseOrWhile = 0; //reset before block since Condition has been run already		 
						ifElseCurrentBlock = IN_IF_BLOCK;
						 
						 }
#line 3440 "parser.tab.c"
    break;

  case 95: /* $@9: %empty  */
#line 1785 "parser.y"
                                                         { printf(BORANGE "\nRULE: IF Statement Block\n\n" RESET);

							if (runIfElseBlock == RUN_IF_BLOCK) {
								
								printf(BORANGE "Done with If Statement.\n\n" RESET);

							}

							ifElseCurrentBlock = IN_ELSE_BLOCK;

						 }
#line 3456 "parser.tab.c"
    break;

  case 96: /* IfStmt: IF $@7 LPAREN Condition RPAREN $@8 Block $@9 ElseStmt  */
#line 1795 "parser.y"
                                                            { printf(BORANGE "\nRULE: ELSE Statement Block\n\n" RESET);

							if (runIfElseBlock == RUN_ELSE_BLOCK) {
								
								printf(BORANGE "Done With Else Statement.\n\n" RESET);

							}
							runIfElseBlock = 0; // reset the pass variable
							ifElseCurrentBlock = 0; // reset the current variable

}
#line 3472 "parser.tab.c"
    break;

  case 99: /* Condition: NUMBER CompOperator NUMBER  */
#line 1809 "parser.y"
                                      {

				int temp1, temp2;
				temp1 = atoi((yyvsp[-2].string));
				temp2 = atoi((yyvsp[0].string));

				if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}
				if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
					if(strcmp((yyvsp[-1].ast),"==") == 0){
						printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
					}
					createWhileCondition((yyvsp[-2].string), (yyvsp[-1].ast), (yyvsp[0].string));
					endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,1,1);
					runWhileBlock = 1;
				}


		}
#line 3497 "parser.tab.c"
    break;

  case 100: /* Condition: ID CompOperator ID  */
#line 1828 "parser.y"
                                       {

				char type1[50];
				char type2[50];
				strcpy(type1, getVariableType((yyvsp[-2].string), scope));
				strcpy(type2, getVariableType((yyvsp[0].string), scope));
				//printf(BORANGE "type1: %s\ntype2: %s\n" RESET, type1, type2);

				// semantic checks
				// are the types the same?
				int check;
				check = strcmp(type1, type2);

				if (!check) { // if the types are the same
					printf(BGREEN "\nID types are the same.\n" RESET);
				} else {
					printf(RED "\nERROR: Trying to compare two ID's that are not of the same type.\n" RESET);
					showSymTable();
					exit(0);
				}

				// are the variables intitalized as a value?
				check = strcmp(getValue((yyvsp[-2].string), scope), "NULL");

				if (!check) { // if first ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, (yyvsp[-2].string));
					showSymTable();
					exit(0);
				}

				check = strcmp(getValue((yyvsp[0].string), scope), "NULL");

				if (!check) { // if second ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, (yyvsp[0].string));
					showSymTable();
					exit(0);
				}

				// go further based on type of id's
				int typeInt, typeFloat, typeChar;
				typeInt = strcmp(type1, "INT");
				typeFloat = strcmp(type1, "FLT");
				typeChar = strcmp(type1, "CHR");

				if (!typeInt) { // if type is integer
					int temp1, temp2;
					temp1 = atoi(getValue((yyvsp[-2].string), scope));
					temp2 = atoi(getValue((yyvsp[0].string), scope));
					//printf(BORANGE "temp1: %d\ntemp2: %d\n" RESET, temp1, temp2);

					if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
					if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
						if(strcmp((yyvsp[-1].ast),"==") == 0){
							printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
						}
						createWhileCondition((yyvsp[-2].string), (yyvsp[-1].ast), (yyvsp[0].string));
						endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,0,0);
						runWhileBlock = 1;
					}
				}
				else if (!typeFloat) { // if type is float
					float temp1, temp2;
					temp1 = atof(getValue((yyvsp[-2].string), scope));
					temp2 = atof(getValue((yyvsp[0].string), scope));
					//printf(BORANGE "temp1: %f\ntemp2: %f\n" RESET, temp1, temp2);

					if (compareFloatOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
					if (compareFloatOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
						if(strcmp((yyvsp[-1].ast),"==") == 0){
							printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
						}
						createWhileCondition((yyvsp[-2].string), (yyvsp[-1].ast), (yyvsp[0].string));
						endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,0,0);
						runWhileBlock = 1;
					}
				}
				else if (!typeChar) { // if type is char
					char temp1[50], temp2[50];
					strcpy(temp1, getValue((yyvsp[-2].string), scope));
					strcpy(temp2, getValue((yyvsp[0].string), scope));
					//printf(BORANGE "temp1: %s\ntemp2: %s\n" RESET, temp1, temp2);

					if (compareCharOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
					}
					if (compareCharOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
						if(strcmp((yyvsp[-1].ast),"==") == 0){
							printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
						}
						createWhileCondition((yyvsp[-2].string), (yyvsp[-1].ast), (yyvsp[0].string));
						endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,0,0);
						runWhileBlock = 1;
					}
				}


		}
#line 3603 "parser.tab.c"
    break;

  case 101: /* Condition: ID CompOperator NUMBER  */
#line 1928 "parser.y"
                                           {

				// is the variable intitalized as a value?
				int check;
				check = strcmp(getValue((yyvsp[-2].string), scope), "NULL");

				if (!check) { // if first ID is NULL
					printf(RED "\nERROR: ID '%s' is not assigned to a value.\n" RESET, (yyvsp[-2].string));
					showSymTable();
					exit(0);
				}

				int temp1, temp2;
				temp1 = atoi(getValue((yyvsp[-2].string), scope));
				temp2 = atoi((yyvsp[0].string));

				if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}
				if (compareIntOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
					if(strcmp((yyvsp[-1].ast),"==") == 0){
						printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
					}
					createWhileCondition((yyvsp[-2].string), (yyvsp[-1].ast), (yyvsp[0].string));
					endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,0,1);
					runWhileBlock = 1;
				}


		}
#line 3638 "parser.tab.c"
    break;

  case 102: /* Condition: FLOATNUM CompOperator FLOATNUM  */
#line 1957 "parser.y"
                                                   {

				float temp1, temp2;
				temp1 = atof((yyvsp[-2].string));
				temp2 = atof((yyvsp[0].string));
				//printf(BORANGE "temp1: %f\ntemp2: %f\n" RESET, temp1, temp2);

				if (compareFloatOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}
				if (compareFloatOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
					if(strcmp((yyvsp[-1].ast),"==") == 0){
						printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
					}
					endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,1,1);
					runWhileBlock = 1;
				}

		}
#line 3662 "parser.tab.c"
    break;

  case 103: /* Condition: CHARID CompOperator CHARID  */
#line 1975 "parser.y"
                                               {

				char temp1[50], temp2[50];
				strcpy(temp1, (yyvsp[-2].string));
				strcpy(temp2, (yyvsp[0].string));
				//printf(BORANGE "temp1: %s\ntemp2: %s\n" RESET, temp1, temp2);

				if (compareCharOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_IF_ELSE) {
					runIfElseBlock = 1;
				}
				if (compareCharOp((yyvsp[-1].ast), temp1, temp2) && inElseOrWhile == UPDATE_WHILE) {
					if(strcmp((yyvsp[-1].ast),"==") == 0){
						printf(BORANGE "\nWARNING: Possible infinite loop detected.\n" RESET);
					}
					endMIPSWhile((yyvsp[-2].string),(yyvsp[-1].ast),(yyvsp[0].string),scope,1,1);
					runWhileBlock = 1;
				}

		}
#line 3686 "parser.tab.c"
    break;


#line 3690 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 2007 "parser.y"


int main(int argc, char**argv)
{

	/*
	#ifdef YYDEBUG
		yydebug = 1;
	#endif
	*/

	printf(BORANGE "\n\n -----------------------> COMPILER STARTED <----------------------- \n\n" RESET);
	clearCalcInput();
	initializeSymbolTable();
	changeIRFile(IR_CODE);
	changeMIPSFile(TEMP_MIPS);

	// initialize ir code file
	initIRcodeFile();

	// initialize mips code file
	initAssemblyFile();
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}
	yyparse();
	

	printf(BORANGE "\n\n --------------------->" RESET);
	printf(BORANGE " COMPILER ENDED " RESET);
	printf(BORANGE "<--------------------- \n\n" RESET);
	
	printf("\n\n ---------------------" RESET);
	printf(BCYAN " SHOW SYMBOL TABLE " RESET);
	printf("--------------------- \n" RESET);
	showSymTable();

	//printf("\n\n ---------------------" RESET);
	//printf(BCYAN " SHOW ARRAY TABLES " RESET);
	//printf("--------------------- \n\n" RESET);
	//showArrTable();

	printf("\n\n\n ---------------------" RESET);
	printf(BCYAN " END SYMBOL TABLE " RESET);
	printf("--------------------- \n\n" RESET);
	
	//printf("\n\n\n ---------------------" RESET);
	//printf(BCYAN " REMOVE UNUSED VARIABLES " RESET);
	//printf("--------------------- n\n" RESET);
	//cleanAssemblyCodeOfUnsuedVariables();
	//printf("--------------------- \n\n" RESET);
}

void yyerror(const char* s) {
	fprintf(stderr, RED "\nBison Parse Error: %s\n" RESET, s);
	showSymTable();
	exit(1);
}
