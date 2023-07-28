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
#include "FunctionST.h"
#include "VarST.h"
#include "AST.h"
#include "IRcode.h"
#include "Assembly.h"
#include "cal.h"

typedef enum { F, T } boolean;

extern int yylex();
extern int yyparse();
extern FILE* yyin;
boolean FunctionFlag = F;

FILE * IRcode;



void yyerror(const char* s);

int sum = 0;
char curArr[50];
int arrIndex = 0;

char curFun[50];

char scope[50] = "Global";
char Global[50] = "Global";
char Local[50] = "Global";


int semanticCheckPassed = 1;

#line 111 "parser.tab.c"

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
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_WRITE = 4,                      /* WRITE  */
  YYSYMBOL_IF = 5,                         /* IF  */
  YYSYMBOL_ELSE = 6,                       /* ELSE  */
  YYSYMBOL_WHILE = 7,                      /* WHILE  */
  YYSYMBOL_RETURN = 8,                     /* RETURN  */
  YYSYMBOL_TYPE = 9,                       /* TYPE  */
  YYSYMBOL_KEYWORD = 10,                   /* KEYWORD  */
  YYSYMBOL_NUMBER = 11,                    /* NUMBER  */
  YYSYMBOL_CHAR = 12,                      /* CHAR  */
  YYSYMBOL_SINGLE_QOUTE = 13,              /* SINGLE_QOUTE  */
  YYSYMBOL_SEMICOLON = 14,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 15,                     /* COMMA  */
  YYSYMBOL_EQ = 16,                        /* EQ  */
  YYSYMBOL_OR = 17,                        /* OR  */
  YYSYMBOL_LSS = 18,                       /* LSS  */
  YYSYMBOL_GTR = 19,                       /* GTR  */
  YYSYMBOL_LEQ = 20,                       /* LEQ  */
  YYSYMBOL_GEQ = 21,                       /* GEQ  */
  YYSYMBOL_LPAREN = 22,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 23,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 24,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 25,                    /* RBRACE  */
  YYSYMBOL_LBRACKET = 26,                  /* LBRACKET  */
  YYSYMBOL_RBRACKET = 27,                  /* RBRACKET  */
  YYSYMBOL_ADD = 28,                       /* ADD  */
  YYSYMBOL_SUB = 29,                       /* SUB  */
  YYSYMBOL_MULTIPLY = 30,                  /* MULTIPLY  */
  YYSYMBOL_DIV = 31,                       /* DIV  */
  YYSYMBOL_YYACCEPT = 32,                  /* $accept  */
  YYSYMBOL_Program = 33,                   /* Program  */
  YYSYMBOL_DeclList = 34,                  /* DeclList  */
  YYSYMBOL_Decl = 35,                      /* Decl  */
  YYSYMBOL_FunDecl = 36,                   /* FunDecl  */
  YYSYMBOL_FuncallStmtList = 37,           /* FuncallStmtList  */
  YYSYMBOL_FuncallStmt = 38,               /* FuncallStmt  */
  YYSYMBOL_ParamDeclList = 39,             /* ParamDeclList  */
  YYSYMBOL_ParamDecl = 40,                 /* ParamDecl  */
  YYSYMBOL_Block = 41,                     /* Block  */
  YYSYMBOL_FunBlock = 42,                  /* FunBlock  */
  YYSYMBOL_VarDeclList = 43,               /* VarDeclList  */
  YYSYMBOL_VarDecl = 44,                   /* VarDecl  */
  YYSYMBOL_ArrayDeclList = 45,             /* ArrayDeclList  */
  YYSYMBOL_ArrayDecl = 46,                 /* ArrayDecl  */
  YYSYMBOL_StmtList = 47,                  /* StmtList  */
  YYSYMBOL_Stmt = 48,                      /* Stmt  */
  YYSYMBOL_AssignStmtList = 49,            /* AssignStmtList  */
  YYSYMBOL_AssignStmt = 50,                /* AssignStmt  */
  YYSYMBOL_WriteStmtList = 51,             /* WriteStmtList  */
  YYSYMBOL_WriteStmt = 52,                 /* WriteStmt  */
  YYSYMBOL_BinOp = 53,                     /* BinOp  */
  YYSYMBOL_MathStatList = 54,              /* MathStatList  */
  YYSYMBOL_MathStat = 55                   /* MathStat  */
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
typedef yytype_int8 yy_state_t;

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
#define YYFINAL  32
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   96

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  24
/* YYNRULES -- Number of rules.  */
#define YYNRULES  53
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  90

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   286


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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,   100,   103,   106,   107,   108,   109,   117,
     141,   143,   145,   166,   167,   170,   173,   193,   196,   199,
     200,   201,   203,   205,   207,   231,   233,   235,   279,   281,
     283,   284,   285,   286,   290,   292,   294,   333,   373,   412,
     492,   538,   540,   542,   571,   575,   579,   583,   587,   589,
     591,   595,   604,   608
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "WRITE", "IF",
  "ELSE", "WHILE", "RETURN", "TYPE", "KEYWORD", "NUMBER", "CHAR",
  "SINGLE_QOUTE", "SEMICOLON", "COMMA", "EQ", "OR", "LSS", "GTR", "LEQ",
  "GEQ", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "LBRACKET", "RBRACKET",
  "ADD", "SUB", "MULTIPLY", "DIV", "$accept", "Program", "DeclList",
  "Decl", "FunDecl", "FuncallStmtList", "FuncallStmt", "ParamDeclList",
  "ParamDecl", "Block", "FunBlock", "VarDeclList", "VarDecl",
  "ArrayDeclList", "ArrayDecl", "StmtList", "Stmt", "AssignStmtList",
  "AssignStmt", "WriteStmtList", "WriteStmt", "BinOp", "MathStatList",
  "MathStat", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-66)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      33,    -2,     1,     3,    30,     7,   -66,    33,   -66,   -66,
       5,   -66,   -66,   -66,    44,   -66,    28,   -66,     6,   -66,
      46,    29,    25,    39,   -66,   -66,   -66,   -66,    46,    38,
     -11,    46,   -66,   -66,    32,   -66,   -66,    -4,   -66,   -66,
      30,   -66,   -12,    50,    52,    62,    45,    25,    40,   -66,
     -66,   -66,    25,    58,   -66,   -66,   -66,   -66,   -66,    56,
     -66,    55,    49,    47,   -66,    51,    53,    59,    61,    64,
      42,   -66,   -66,   -66,   -66,    73,    54,   -66,    71,   -66,
      72,   -66,    -5,   -66,    79,   -66,    80,   -66,    70,    60
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    53,     0,     0,    52,     0,     2,     4,     5,    33,
      11,     7,     8,     6,    29,    30,    35,    32,    42,    31,
      49,     0,    13,     0,    44,    45,    46,    47,     0,     0,
       0,     0,     1,     3,     0,    10,    28,     0,    34,    41,
      53,    48,     0,     0,     0,     0,     0,    13,     0,    51,
      43,    24,    13,     0,    50,    39,    38,    40,    16,     0,
      14,     0,     0,     0,    12,     0,     0,     0,     0,     0,
       0,     9,    27,    36,    37,     0,     0,    20,    23,    19,
      26,    21,     0,    18,     0,    22,     0,    25,     0,     0
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,    78,   -66,   -66,    77,   -66,    -9,   -66,   -66,
     -66,    10,   -65,     9,   -45,   -14,   -66,    74,   -66,    75,
     -66,    -3,    76,     2
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     5,     6,     7,     8,     9,    10,    46,    47,    71,
      76,    77,    11,    79,    12,    13,    14,    15,    16,    17,
      18,    28,    19,    20
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      36,    31,    55,    51,    29,    78,    30,    32,    34,    51,
       2,    52,    21,    78,    21,    53,    24,    25,    26,    27,
      22,    53,    23,    44,    23,    80,    24,    25,    26,    27,
      49,    37,    40,    54,    45,    80,     1,     2,    60,    31,
      42,    43,     3,    62,     4,     1,     2,     1,     2,    40,
      48,    75,    50,     4,    22,     4,    81,     4,    24,    25,
      26,    27,    68,    69,    56,    58,    57,    61,    59,    63,
      64,    65,    66,    72,    67,    73,    82,    70,    74,    83,
      84,    86,    88,    89,    51,    33,    53,    35,    85,    87,
      38,     0,     0,    39,     0,     0,    41
};

static const yytype_int8 yycheck[] =
{
      14,     4,    14,    14,     3,    70,     3,     0,     3,    14,
       4,    22,    16,    78,    16,    26,    28,    29,    30,    31,
      22,    26,    26,    21,    26,    70,    28,    29,    30,    31,
      28,     3,     3,    31,     9,    80,     3,     4,    47,    42,
      11,    12,     9,    52,    11,     3,     4,     3,     4,     3,
      11,     9,    14,    11,    22,    11,    70,    11,    28,    29,
      30,    31,    11,    12,    14,     3,    14,    27,    23,    11,
      14,    16,    23,    14,    27,    14,     3,    24,    14,    25,
       9,     9,     3,     3,    14,     7,    26,    10,    78,    80,
      16,    -1,    -1,    18,    -1,    -1,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     9,    11,    33,    34,    35,    36,    37,
      38,    44,    46,    47,    48,    49,    50,    51,    52,    54,
      55,    16,    22,    26,    28,    29,    30,    31,    53,     3,
       3,    53,     0,    34,     3,    37,    47,     3,    49,    51,
       3,    54,    11,    12,    55,     9,    39,    40,    11,    55,
      14,    14,    22,    26,    55,    14,    14,    14,     3,    23,
      39,    27,    39,    11,    14,    16,    23,    27,    11,    12,
      24,    41,    14,    14,    14,     9,    42,    43,    44,    45,
      46,    47,     3,    25,     9,    43,     9,    45,     3,     3
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    36,
      37,    37,    38,    39,    39,    39,    40,    40,    41,    42,
      42,    42,    43,    43,    44,    45,    45,    46,    47,    47,
      48,    48,    48,    48,    49,    49,    50,    50,    50,    50,
      50,    51,    51,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    55
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     1,     6,
       2,     1,     5,     0,     2,     1,     2,     0,     3,     1,
       1,     1,     2,     1,     3,     2,     1,     6,     2,     1,
       1,     1,     1,     1,     2,     1,     7,     7,     4,     4,
       4,     2,     1,     3,     1,     1,     1,     1,     2,     1,
       3,     3,     1,     1
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
#line 78 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 831 "parser.tab.c"
        break;

    case YYSYMBOL_NUMBER: /* NUMBER  */
#line 79 "parser.y"
         { fprintf(yyoutput, "%d", ((*yyvaluep).string)); }
#line 837 "parser.tab.c"
        break;

    case YYSYMBOL_CHAR: /* CHAR  */
#line 80 "parser.y"
         { fprintf(yyoutput, "%s", ((*yyvaluep).string)); }
#line 843 "parser.tab.c"
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
#line 93 "parser.y"
                   { (yyval.ast) = (yyvsp[0].ast);
					 printf("\n--- Abstract Syntax Tree ---\n\n");
					 printAST((yyval.ast),0);
					}
#line 1236 "parser.tab.c"
    break;

  case 3: /* DeclList: Decl DeclList  */
#line 100 "parser.y"
                                { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);
							}
#line 1244 "parser.tab.c"
    break;

  case 4: /* DeclList: Decl  */
#line 103 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 1250 "parser.tab.c"
    break;

  case 9: /* FunDecl: TYPE ID LPAREN ParamDeclList RPAREN Block  */
#line 117 "parser.y"
                                                          {printf("\nRULE: Function\n");
							
								char id1[50];
								char type[50];
								strcpy(id1, (yyvsp[-4].string));
								strcpy(type, (yyvsp[-5].string));
								strcpy(scope, Local);
								int inSymTab = found((yyvsp[-4].string), scope);
								
								if (inSymTab == 0){
									addItemVST(id1, "Fun", (yyvsp[-5].string), 0, scope);

									addItemFST(id1, "Fun", &type, 0, &id1, &scope);
								}
								else{					
									printf("SEMANTIC ERROR: Fun %s is already in the symbol table", (yyvsp[-4].string));
								}
								showVarSymTable();
								printFuncTable();

								(yyval.ast) = AST_Type("Fun", (yyvsp[-5].string), (yyvsp[-4].string));
								
			}
#line 1278 "parser.tab.c"
    break;

  case 10: /* FuncallStmtList: FuncallStmt FuncallStmtList  */
#line 141 "parser.y"
                                             {(yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);}
#line 1285 "parser.tab.c"
    break;

  case 11: /* FuncallStmtList: FuncallStmt  */
#line 143 "parser.y"
                                      {(yyval.ast) = (yyvsp[0].ast);}
#line 1291 "parser.tab.c"
    break;

  case 12: /* FuncallStmt: ID LPAREN ParamDeclList RPAREN SEMICOLON  */
#line 145 "parser.y"
                                                      {printf("\nRULE: Function Call\n");
							
								char id1[50];
								strcpy(id1, (yyvsp[-4].string));
								strcpy(scope, Local);
								int inSymTab = found(id1, scope);
								
								if (inSymTab == 0){
									printf("SEMANTIC ERROR: Fun %s is not in the symbol table", (yyvsp[-4].string));
								}
								else{					
									

								}

								printFuncTable();

								(yyval.ast) = AST_Type("FunCall", (yyvsp[-4].string), "NULL");
								
			}
#line 1316 "parser.tab.c"
    break;

  case 14: /* ParamDeclList: ParamDecl ParamDeclList  */
#line 167 "parser.y"
                                                  {(yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);}
#line 1323 "parser.tab.c"
    break;

  case 15: /* ParamDeclList: ParamDecl  */
#line 170 "parser.y"
                                    {(yyval.ast) = (yyvsp[0].ast);}
#line 1329 "parser.tab.c"
    break;

  case 16: /* ParamDecl: TYPE ID  */
#line 173 "parser.y"
                   {printf("\nRULE: Variable declaration\n");						
									char id1[50];
									symTabAccess();
									int inSymTab = found((yyvsp[0].string), scope);

									
									if (inSymTab == 0) 
										addItemVST((yyvsp[0].string), "Var", (yyvsp[-1].string), 0, scope);
									else						
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[0].string));

									showVarSymTable();
									
									sprintf(id1, "%s", (yyvsp[0].string));
									int numid = getItemID(id1, scope);  
									emitConstantIntAssignment ((yyvsp[0].string), numid);								

									
								    (yyval.ast) = AST_Type("Type",(yyvsp[-1].string),(yyvsp[0].string));  	
								}
#line 1354 "parser.tab.c"
    break;

  case 22: /* VarDeclList: VarDecl VarDeclList  */
#line 203 "parser.y"
                                    {(yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);}
#line 1361 "parser.tab.c"
    break;

  case 23: /* VarDeclList: VarDecl  */
#line 205 "parser.y"
                                  {(yyval.ast) = (yyvsp[0].ast);}
#line 1367 "parser.tab.c"
    break;

  case 24: /* VarDecl: TYPE ID SEMICOLON  */
#line 207 "parser.y"
                                  { printf("\nRULE: Variable declaration\n");

									char id1[50];

									symTabAccess();
									int inSymTab = found((yyvsp[-1].string), scope);

									
									if (inSymTab == 0) 
										addItemVST((yyvsp[-1].string), "Var", (yyvsp[-2].string), 0, scope);
									else						
										printf("SEMANTIC ERROR: Var %s is already in the symbol table", (yyvsp[-1].string));

									showVarSymTable();
									
									sprintf(id1, "%s", (yyvsp[-1].string));
									int numid = getItemID(id1, scope);   
									emitConstantIntAssignment ((yyvsp[-1].string), numid);								

									
								    (yyval.ast) = AST_Type("Type",(yyvsp[-2].string),(yyvsp[-1].string));  	 
								}
#line 1394 "parser.tab.c"
    break;

  case 25: /* ArrayDeclList: ArrayDecl ArrayDeclList  */
#line 231 "parser.y"
                                        {(yyvsp[-1].ast)->left = (yyvsp[0].ast);
							  (yyval.ast) = (yyvsp[-1].ast);}
#line 1401 "parser.tab.c"
    break;

  case 26: /* ArrayDeclList: ArrayDecl  */
#line 233 "parser.y"
                                    {(yyval.ast) = (yyvsp[0].ast);}
#line 1407 "parser.tab.c"
    break;

  case 27: /* ArrayDecl: TYPE ID LBRACKET NUMBER RBRACKET SEMICOLON  */
#line 235 "parser.y"
                                                       { printf("\nRULE: Array declaration %s\n", (yyvsp[-4].string));
									char id1[50];
									(yyvsp[-2].string) = atoi((yyvsp[-2].string));

									char concat[50];
									sprintf(concat, "%s[%d]", (yyvsp[-4].string), (yyvsp[-2].string));

									
									char temp[50];

									
									int inSymTab = found((yyvsp[-4].string), scope);

									if (inSymTab == 0){
										printf("Adding array to symbol table\n");
										int tempint = (yyvsp[-2].string);

										for (int i = 0; i < (yyvsp[-2].string); i++){
											char arrayname[50];
											
											sprintf(temp, "%d", i);

											sprintf(arrayname, "%s[%s]", (yyvsp[-4].string), temp);

											addItemVST(arrayname, "Array", (yyvsp[-5].string), (yyvsp[-2].string), &scope);
											
											tempint--;

	
										}
									}else{
														
										printf("SEMANTIC ERROR: Array %s is already in the symbol table", (yyvsp[-4].string));
									}
									showVarSymTable();
									
									sprintf(id1, "%s", (yyvsp[-4].string));
									int numid = getItemID(id1, scope);   
									emitConstantIntAssignment ((yyvsp[-4].string), numid);								
									
								    (yyval.ast) = AST_Type("Type",(yyvsp[-5].string),concat);
									printf("%s", (yyval.ast)->LHS);
								}
#line 1455 "parser.tab.c"
    break;

  case 28: /* StmtList: Stmt StmtList  */
#line 279 "parser.y"
                       { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
					(yyval.ast) = (yyvsp[-1].ast);}
#line 1462 "parser.tab.c"
    break;

  case 29: /* StmtList: Stmt  */
#line 281 "parser.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 1468 "parser.tab.c"
    break;

  case 30: /* Stmt: AssignStmtList  */
#line 283 "parser.y"
                     {printf("AssignStmt\n");}
#line 1474 "parser.tab.c"
    break;

  case 31: /* Stmt: MathStatList  */
#line 284 "parser.y"
                       {printf("MathStat\n");}
#line 1480 "parser.tab.c"
    break;

  case 32: /* Stmt: WriteStmtList  */
#line 285 "parser.y"
                        {printf("WriteStmt\n");}
#line 1486 "parser.tab.c"
    break;

  case 33: /* Stmt: FuncallStmtList  */
#line 286 "parser.y"
                          {printf("FuncallStmt\n");}
#line 1492 "parser.tab.c"
    break;

  case 34: /* AssignStmtList: AssignStmt AssignStmtList  */
#line 290 "parser.y"
                                         { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
					(yyval.ast) = (yyvsp[-1].ast);}
#line 1499 "parser.tab.c"
    break;

  case 35: /* AssignStmtList: AssignStmt  */
#line 292 "parser.y"
                                            { (yyval.ast) = (yyvsp[0].ast); }
#line 1505 "parser.tab.c"
    break;

  case 36: /* AssignStmt: ID LBRACKET NUMBER RBRACKET EQ NUMBER SEMICOLON  */
#line 294 "parser.y"
                                                                { printf("\nRULE: Set Val of array at certine index\n"); 
									
									char concat[50];
									sprintf(concat, "%s[%s]", (yyvsp[-6].string), (yyvsp[-4].string));
									

									if (strcmp(scope, Global) == 0){
										if(found(concat, scope) != 1) {  
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", (yyvsp[-6].string), scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setVal(concat, (yyvsp[-1].string), scope);
											(yyval.ast) = AST_assignment("=",concat, (yyvsp[-1].string));
									
											int numid = getItemID(concat, scope);    
											emitIRAssignment(concat, (yyvsp[-1].string), numid);         
											memset(concat, 0, sizeof(concat));
										}

									}else{
										if(foundFST(concat, scope) != 1) {  
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", (yyvsp[-6].string), scope);
											semanticCheckPassed = 0;
											setIntFST(concat, (yyvsp[-1].string), scope);
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setIntFST(concat, (yyvsp[-1].string), scope);
											(yyval.ast) = AST_assignment("=",concat, (yyvsp[-1].string));
									
											int numid = getIDFST(concat, scope);   
											emitIRAssignment(concat, (yyvsp[-1].string), numid);            
											memset(concat, 0, sizeof(concat));
										}

									}							
								}
#line 1549 "parser.tab.c"
    break;

  case 37: /* AssignStmt: ID LBRACKET NUMBER RBRACKET EQ CHAR SEMICOLON  */
#line 333 "parser.y"
                                                        { printf("\nRULE: Set Val of array at certine index\n"); 
									
									char concat[50];
									sprintf(concat, "%s[%s]", (yyvsp[-6].string), (yyvsp[-4].string));
									

									if (strcmp(scope, Global) == 0){
										if(found(concat, scope) != 1) { 
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", (yyvsp[-6].string), scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setcharVal(concat, (yyvsp[-1].string), scope);
											(yyval.ast) = AST_assignment("=",concat, (yyvsp[-1].string));
									
											int numid = getItemID(concat, scope);    
											emitIRAssignment(concat, (yyvsp[-1].string), numid);         

											memset(concat, 0, sizeof(concat));
										}

									}else{
										if(foundFST(concat, scope) != 1) {  
											printf("SEMANTIC ERROR: Array %s has NOT been declared in scope %s \n", (yyvsp[-6].string), scope);
											semanticCheckPassed = 0;
										}
										if(semanticCheckPassed == 1) {
											printf("\n\nRule is semantically correct!\n\n");
											setCharFST(concat, (yyvsp[-1].string), scope);
											(yyval.ast) = AST_assignment("=",concat, (yyvsp[-1].string));
									
											int numid = getIDFST(concat, scope);    
											emitIRAssignment(concat, (yyvsp[-1].string), numid);             
											memset(concat, 0, sizeof(concat));
										}

									}							
								}
#line 1593 "parser.tab.c"
    break;

  case 38: /* AssignStmt: ID EQ CHAR SEMICOLON  */
#line 373 "parser.y"
                              { printf("\nRULE: Set String\n"); 
	
					char char1[50];
					char id1[50];
					sprintf(char1, "%s", (yyvsp[-1].string));
					sprintf(id1, "%s", (yyvsp[-3].string));
					if (strcmp(scope, Global) == 0){

						if(found(id1, scope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-3].string), scope);
							semanticCheckPassed = 0;
						}

						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							setcharVal(id1, char1, scope);
							showVarSymTable();
							(yyval.ast) = AST_assignment("=",(yyvsp[-3].string), (yyvsp[-1].string));
							int numid = getItemID((yyvsp[-3].string), scope);    
							emitIRAssignment((yyvsp[-3].string), (yyvsp[-1].string), numid);             
						}

					}else{
						if(foundFST(id1, scope) != 1) {
							printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-3].string), scope);
							semanticCheckPassed = 0;
						}
						if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							setCharFST(id1, char1, scope);
							showVarSymTable();
							(yyval.ast) = AST_assignment("=",(yyvsp[-3].string), (yyvsp[-1].string));
							int numid = getValFST((yyvsp[-3].string), scope);   
							emitIRAssignment((yyvsp[-3].string), (yyvsp[-1].string), numid);              
						}

					}
				}
#line 1636 "parser.tab.c"
    break;

  case 39: /* AssignStmt: ID EQ NUMBER SEMICOLON  */
#line 412 "parser.y"
                                 { printf("\nRULE: Set Val\n"); 


						char str[50];
						char id1[50];
						char id2[50];

						if (strcmp(scope, Global) == 0){


							if(found((yyvsp[-3].string), scope) != 1) {
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-3].string), scope);
								semanticCheckPassed = 0;
							}


							if (semanticCheckPassed == 1) {
								printf("\n\nRule is semantically correct!\n\n");
								sprintf(id2, "%s", (yyvsp[-1].string)); 
								sprintf(id1, "%s", (yyvsp[-3].string));
								symTabAccess();
								int CheckForFloat = 0;
								for(int i = 0; (yyvsp[-1].string)[i] != '\0'; ++i)
								{
									if((yyvsp[-1].string)[i] == '.')
									{
									CheckForFloat = 1;
									break;
									}
								}
								if (CheckForFloat == 1){
									printf("%s\n",(yyvsp[-1].string));
									setfloatVal(id1, (yyvsp[-1].string), scope);
								}else{
									setVal(id1, (yyvsp[-1].string), scope);
								}



								showVarSymTable();
								(yyval.ast) = AST_assignment("=",(yyvsp[-3].string), id2);
								int numid = getItemID(id1, scope);    
								emitIRAssignment(id1, id2, numid);             
								

							}
						}else{
							if(foundFST((yyvsp[-3].string), scope) != 1) {
								printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-3].string), scope);
								semanticCheckPassed = 0;
							}
							if (semanticCheckPassed == 1) {
								printf("\n\nRule is semantically correct!\n\n");
								sprintf(id2, "%s", (yyvsp[-1].string)); 
								sprintf(id1, "%s", (yyvsp[-3].string));
								int CheckForFloat = 0;
								for(int i = 0; (yyvsp[-1].string)[i] != '\0'; ++i)
								{
									if((yyvsp[-1].string)[i] == '.')
									{
									CheckForFloat = 1;
									break;
									}
								}
								if (CheckForFloat == 1){
									printf("%s\n",(yyvsp[-1].string));
									setDecFST(id1, (yyvsp[-1].string), scope);
								}else{
									 
									setIntFST(id1, (yyvsp[-1].string), scope);
								}
								printFuncTable();
								(yyval.ast) = AST_assignment("=",(yyvsp[-3].string), id2);
								int numid = getIDFST(id1, scope);   
								emitIRAssignment(id1, id2, numid);            
								emitMIPSConstantIntAssignment(id1, id2, numid);

							}
						} 
					}
#line 1721 "parser.tab.c"
    break;

  case 40: /* AssignStmt: ID EQ MathStat SEMICOLON  */
#line 492 "parser.y"
                                  {
					char id1[50];
					char id2[50];
					FILE * ResultF;
					sprintf(id1, "%s", (yyvsp[-3].string));
					char command[50], mathVal[50];
					char ch;
					int i = 0;
					int numid = getItemID(id1, scope);
					reverseNumArr();
					strcpy( command, "python3 Operations.py" );
					printf("\n");
					addCalcFile();
					addOpArr('\0');
					system(command);
					sleep(1);
					ResultF = fopen("./Calc/Results/CalcF.txt_results.txt", "r");
					fgets(mathVal,20,ResultF);
					int x = atoi(mathVal);
					fclose(ResultF);

					int CheckForFloat = 0;
					for(int i = 0; mathVal[i] != '\0'; ++i){
						if(mathVal[i] == '.'){
							CheckForFloat = 1;
							break;
						}
					}
						if (CheckForFloat == 1){
							printf("%s\n",mathVal);
							setfloatVal((yyvsp[-3].string), mathVal, scope);
						}else{
							setVal((yyvsp[-3].string), mathVal, scope);
						}
					sprintf(id2, "%s", mathVal);	
					(yyval.ast) = AST_assignment("=",(yyvsp[-3].string),mathVal);
					emitMIPSConstantIntAssignment(id1, mathVal, numid);	
					
					showVarSymTable();
					printOpArr();
					printArr();
					clearClacFile();
					clearArr();
					clearOpArr();
		}
#line 1771 "parser.tab.c"
    break;

  case 41: /* WriteStmtList: WriteStmt WriteStmtList  */
#line 538 "parser.y"
                                      { (yyvsp[-1].ast)->left = (yyvsp[0].ast);
					(yyval.ast) = (yyvsp[-1].ast);}
#line 1778 "parser.tab.c"
    break;

  case 42: /* WriteStmtList: WriteStmt  */
#line 540 "parser.y"
                                                 { (yyval.ast) = (yyvsp[0].ast); }
#line 1784 "parser.tab.c"
    break;

  case 43: /* WriteStmt: WRITE ID SEMICOLON  */
#line 542 "parser.y"
                             { printf("\nRULE: WRITE STATMENT\n");

					char id1[50];
					sprintf(id1, "%s", (yyvsp[-1].string));
					char *tyoe = getVariableType(id1, scope);
					char type[50];
					sprintf(type, "%s", tyoe);
					printf("Type: %s\n", type);
					(yyval.ast) = AST_Write("write",type, (yyvsp[-1].string));
					
					int numid = getItemID(id1, scope);


					  
					if (found((yyvsp[-1].string), scope) != 1) {	 
						printf("SEMANTIC ERROR: Variable %s has NOT been declared in scope %s \n", (yyvsp[-1].string), scope);
						semanticCheckPassed = 0;
					}

					if (semanticCheckPassed == 1) {
							printf("\n\nRule is semantically correct!\n\n");
							emitWriteId((yyvsp[-1].string));	 				
							emitMIPSWriteId((yyvsp[-1].string),numid);		 
						}
					emitMIPSWriteId((yyvsp[-1].string),numid);
				}
#line 1815 "parser.tab.c"
    break;

  case 44: /* BinOp: ADD  */
#line 571 "parser.y"
                {
			addOpArr('+');
		}
#line 1823 "parser.tab.c"
    break;

  case 45: /* BinOp: SUB  */
#line 575 "parser.y"
                        {
			addOpArr('-');
		}
#line 1831 "parser.tab.c"
    break;

  case 46: /* BinOp: MULTIPLY  */
#line 579 "parser.y"
                                {
			addOpArr('*');
		}
#line 1839 "parser.tab.c"
    break;

  case 47: /* BinOp: DIV  */
#line 583 "parser.y"
                        {
			addOpArr('/');
		}
#line 1847 "parser.tab.c"
    break;

  case 48: /* MathStatList: MathStat MathStatList  */
#line 587 "parser.y"
                                    {(yyvsp[-1].ast)->left = (yyvsp[0].ast);
					(yyval.ast) = (yyvsp[-1].ast);}
#line 1854 "parser.tab.c"
    break;

  case 49: /* MathStatList: MathStat  */
#line 589 "parser.y"
                                          { (yyval.ast) = (yyvsp[0].ast); }
#line 1860 "parser.tab.c"
    break;

  case 50: /* MathStat: NUMBER BinOp MathStat  */
#line 591 "parser.y"
                                        {
				addNumArr((yyvsp[-2].string));
			}
#line 1868 "parser.tab.c"
    break;

  case 51: /* MathStat: ID BinOp MathStat  */
#line 595 "parser.y"
                                                {

					symTabAccess();
					int id1;
					id1 = getVal((yyvsp[-2].string), scope);
					addIDNumArr(id1);  
					
			}
#line 1881 "parser.tab.c"
    break;

  case 52: /* MathStat: NUMBER  */
#line 604 "parser.y"
                                        {
				addNumArr((yyvsp[0].string));	
			}
#line 1889 "parser.tab.c"
    break;

  case 53: /* MathStat: ID  */
#line 608 "parser.y"
                                {
					symTabAccess();
					int id1;
					id1 = getVal((yyvsp[0].string), scope);
					addIDNumArr(id1);	 
					}
#line 1900 "parser.tab.c"
    break;


#line 1904 "parser.tab.c"

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

#line 615 "parser.y"


int main(int argc, char**argv)
{

	printf("\n\n##### COMPILER STARTED #####\n\n");
	
	if (argc > 1){
	  if(!(yyin = fopen(argv[1], "r")))
          {
		perror(argv[1]);
		return(1);
	  }
	}

 
	initIRcodeFile();
	initAssemblyFile();

 
	yyparse();

 
	emitEndOfAssemblyCode();

}

void yyerror(const char* s) {
	fprintf(stderr, "Parse ERROR: %s\n", s);
	exit(1);
}
