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
#line 3 "parser.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "header.h"
#include "symbolTable.h"
int linenumber = 1;
AST_NODE *prog;

extern int g_anyErrorOccur;

static inline AST_NODE* makeSibling(AST_NODE *a, AST_NODE *b)
{
    while (a->rightSibling) {
        a = a->rightSibling;
    }
    if (b == NULL) {
        return a;
    }
    b = b->leftmostSibling;
    a->rightSibling = b;

    b->leftmostSibling = a->leftmostSibling;
    b->parent = a->parent;
    while (b->rightSibling) {
        b = b->rightSibling;
        b->leftmostSibling = a->leftmostSibling;
        b->parent = a->parent;
    }
    return b;
}

static inline AST_NODE* makeChild(AST_NODE *parent, AST_NODE *child)
{
    if (child == NULL) {
        return parent;
    }
    if (parent->child) {
        makeSibling(parent->child, child);
    } else {
        child = child->leftmostSibling;
        parent->child = child;
        while (child) {
            child->parent = parent;
            child = child->rightSibling;
        }
    }
    return parent;
}

static AST_NODE* makeFamily(AST_NODE *parent, int childrenCount, ...)
{
    va_list childrenList;
    va_start(childrenList, childrenCount);
    AST_NODE* child = va_arg(childrenList, AST_NODE*);
    makeChild(parent, child);
    AST_NODE* tmp = child;
    int index = 1;
    for (index = 1; index < childrenCount; ++index) {
        child = va_arg(childrenList, AST_NODE*);
        tmp = makeSibling(tmp, child);
    }
    va_end(childrenList);
    return parent;
}

static inline AST_NODE* makeIDNode(char *lexeme, IDENTIFIER_KIND idKind)
{
    AST_NODE* identifier = Allocate(IDENTIFIER_NODE);
    identifier->semantic_value.identifierSemanticValue.identifierName = lexeme;
    identifier->semantic_value.identifierSemanticValue.kind = idKind;
    identifier->semantic_value.identifierSemanticValue.symbolTableEntry = NULL;
    return identifier;
}

static inline AST_NODE* makeStmtNode(STMT_KIND stmtKind)
{
    AST_NODE* stmtNode = Allocate(STMT_NODE);
    stmtNode->semantic_value.stmtSemanticValue.kind = stmtKind;
    return stmtNode;
}

static inline AST_NODE* makeDeclNode(DECL_KIND declKind)
{
    AST_NODE* declNode = Allocate(DECLARATION_NODE);
    declNode->semantic_value.declSemanticValue.kind = declKind;
    return declNode;
}

static inline AST_NODE* makeExprNode(EXPR_KIND exprKind, int operationEnumValue)
{
    AST_NODE* exprNode = Allocate(EXPR_NODE);
    exprNode->semantic_value.exprSemanticValue.isConstEval = 0;
    exprNode->semantic_value.exprSemanticValue.kind = exprKind;
    if (exprKind == BINARY_OPERATION) {
        exprNode->semantic_value.exprSemanticValue.op.binaryOp = operationEnumValue;
    } else if (exprKind == UNARY_OPERATION) {
        exprNode->semantic_value.exprSemanticValue.op.unaryOp = operationEnumValue;
    } else {
        printf("Error in static inline AST_NODE* makeExprNode(EXPR_KIND exprKind, int operationEnumValue)\n");
    }
    return exprNode;
}


#line 178 "parser.tab.c"

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
  YYSYMBOL_CONST = 4,                      /* CONST  */
  YYSYMBOL_VOID = 5,                       /* VOID  */
  YYSYMBOL_INT = 6,                        /* INT  */
  YYSYMBOL_FLOAT = 7,                      /* FLOAT  */
  YYSYMBOL_IF = 8,                         /* IF  */
  YYSYMBOL_ELSE = 9,                       /* ELSE  */
  YYSYMBOL_WHILE = 10,                     /* WHILE  */
  YYSYMBOL_FOR = 11,                       /* FOR  */
  YYSYMBOL_TYPEDEF = 12,                   /* TYPEDEF  */
  YYSYMBOL_OP_ASSIGN = 13,                 /* OP_ASSIGN  */
  YYSYMBOL_OP_OR = 14,                     /* OP_OR  */
  YYSYMBOL_OP_AND = 15,                    /* OP_AND  */
  YYSYMBOL_OP_NOT = 16,                    /* OP_NOT  */
  YYSYMBOL_OP_EQ = 17,                     /* OP_EQ  */
  YYSYMBOL_OP_NE = 18,                     /* OP_NE  */
  YYSYMBOL_OP_GT = 19,                     /* OP_GT  */
  YYSYMBOL_OP_LT = 20,                     /* OP_LT  */
  YYSYMBOL_OP_GE = 21,                     /* OP_GE  */
  YYSYMBOL_OP_LE = 22,                     /* OP_LE  */
  YYSYMBOL_OP_PLUS = 23,                   /* OP_PLUS  */
  YYSYMBOL_OP_MINUS = 24,                  /* OP_MINUS  */
  YYSYMBOL_OP_TIMES = 25,                  /* OP_TIMES  */
  YYSYMBOL_OP_DIVIDE = 26,                 /* OP_DIVIDE  */
  YYSYMBOL_MK_LB = 27,                     /* MK_LB  */
  YYSYMBOL_MK_RB = 28,                     /* MK_RB  */
  YYSYMBOL_MK_LPAREN = 29,                 /* MK_LPAREN  */
  YYSYMBOL_MK_RPAREN = 30,                 /* MK_RPAREN  */
  YYSYMBOL_MK_LBRACE = 31,                 /* MK_LBRACE  */
  YYSYMBOL_MK_RBRACE = 32,                 /* MK_RBRACE  */
  YYSYMBOL_MK_COMMA = 33,                  /* MK_COMMA  */
  YYSYMBOL_MK_SEMICOLON = 34,              /* MK_SEMICOLON  */
  YYSYMBOL_MK_DOT = 35,                    /* MK_DOT  */
  YYSYMBOL_ERROR = 36,                     /* ERROR  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_YYACCEPT = 38,                  /* $accept  */
  YYSYMBOL_program = 39,                   /* program  */
  YYSYMBOL_global_decl_list = 40,          /* global_decl_list  */
  YYSYMBOL_global_decl = 41,               /* global_decl  */
  YYSYMBOL_function_decl = 42,             /* function_decl  */
  YYSYMBOL_function_head = 43,             /* function_head  */
  YYSYMBOL_opt_param_list = 44,            /* opt_param_list  */
  YYSYMBOL_param_list = 45,                /* param_list  */
  YYSYMBOL_param = 46,                     /* param  */
  YYSYMBOL_dim_fn = 47,                    /* dim_fn  */
  YYSYMBOL_expr_null = 48,                 /* expr_null  */
  YYSYMBOL_block = 49,                     /* block  */
  YYSYMBOL_decl_list = 50,                 /* decl_list  */
  YYSYMBOL_decl = 51,                      /* decl  */
  YYSYMBOL_type_decl = 52,                 /* type_decl  */
  YYSYMBOL_var_decl = 53,                  /* var_decl  */
  YYSYMBOL_type = 54,                      /* type  */
  YYSYMBOL_id_list = 55,                   /* id_list  */
  YYSYMBOL_dim_decl = 56,                  /* dim_decl  */
  YYSYMBOL_cexpr = 57,                     /* cexpr  */
  YYSYMBOL_mcexpr = 58,                    /* mcexpr  */
  YYSYMBOL_cfactor = 59,                   /* cfactor  */
  YYSYMBOL_init_id_list = 60,              /* init_id_list  */
  YYSYMBOL_init_id = 61,                   /* init_id  */
  YYSYMBOL_stmt_list = 62,                 /* stmt_list  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_assign_expr_list = 64,          /* assign_expr_list  */
  YYSYMBOL_nonempty_assign_expr_list = 65, /* nonempty_assign_expr_list  */
  YYSYMBOL_test = 66,                      /* test  */
  YYSYMBOL_assign_expr = 67,               /* assign_expr  */
  YYSYMBOL_relop_expr = 68,                /* relop_expr  */
  YYSYMBOL_relop_term = 69,                /* relop_term  */
  YYSYMBOL_relop_factor = 70,              /* relop_factor  */
  YYSYMBOL_rel_op = 71,                    /* rel_op  */
  YYSYMBOL_relop_expr_list = 72,           /* relop_expr_list  */
  YYSYMBOL_nonempty_relop_expr_list = 73,  /* nonempty_relop_expr_list  */
  YYSYMBOL_expr = 74,                      /* expr  */
  YYSYMBOL_add_op = 75,                    /* add_op  */
  YYSYMBOL_term = 76,                      /* term  */
  YYSYMBOL_mul_op = 77,                    /* mul_op  */
  YYSYMBOL_factor = 78,                    /* factor  */
  YYSYMBOL_var_ref = 79,                   /* var_ref  */
  YYSYMBOL_dim_list = 80                   /* dim_list  */
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
#define YYFINAL  22
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   247

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  38
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  207

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
       0,   166,   166,   167,   170,   174,   180,   184,   190,   197,
     202,   208,   215,   221,   226,   230,   236,   241,   246,   251,
     257,   261,   267,   272,   277,   282,   287,   292,   297,   301,
     307,   311,   317,   322,   330,   335,   342,   346,   352,   356,
     360,   364,   369,   373,   378,   383,   388,   393,   398,   403,
     409,   414,   420,   424,   430,   434,   438,   444,   448,   456,
     460,   465,   470,   475,   480,   485,   490,   494,   499,   506,
     511,   516,   520,   526,   532,   538,   544,   548,   555,   559,
     566,   570,   576,   580,   584,   588,   592,   596,   603,   608,
     613,   617,   623,   627,   633,   637,   643,   647,   653,   657,
     663,   667,   672,   677,   682,   689,   696,   701,   708,   715,
     719,   724,   731,   735,   743,   747
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "CONST", "VOID",
  "INT", "FLOAT", "IF", "ELSE", "WHILE", "FOR", "TYPEDEF", "OP_ASSIGN",
  "OP_OR", "OP_AND", "OP_NOT", "OP_EQ", "OP_NE", "OP_GT", "OP_LT", "OP_GE",
  "OP_LE", "OP_PLUS", "OP_MINUS", "OP_TIMES", "OP_DIVIDE", "MK_LB",
  "MK_RB", "MK_LPAREN", "MK_RPAREN", "MK_LBRACE", "MK_RBRACE", "MK_COMMA",
  "MK_SEMICOLON", "MK_DOT", "ERROR", "RETURN", "$accept", "program",
  "global_decl_list", "global_decl", "function_decl", "function_head",
  "opt_param_list", "param_list", "param", "dim_fn", "expr_null", "block",
  "decl_list", "decl", "type_decl", "var_decl", "type", "id_list",
  "dim_decl", "cexpr", "mcexpr", "cfactor", "init_id_list", "init_id",
  "stmt_list", "stmt", "assign_expr_list", "nonempty_assign_expr_list",
  "test", "assign_expr", "relop_expr", "relop_term", "relop_factor",
  "rel_op", "relop_expr_list", "nonempty_relop_expr_list", "expr",
  "add_op", "term", "mul_op", "factor", "var_ref", "dim_list", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-153)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-12)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     122,    22,    25,  -153,  -153,   172,    75,   122,  -153,  -153,
      36,   122,  -153,  -153,  -153,    77,    88,   152,  -153,  -153,
      82,    82,  -153,  -153,   168,  -153,  -153,    91,   156,    83,
      10,    61,    95,  -153,    68,   158,   160,   105,   106,   110,
    -153,   127,  -153,     6,  -153,    23,    65,    83,   148,   130,
    -153,   131,   162,  -153,  -153,  -153,    10,    86,   170,  -153,
      10,    70,  -153,    61,   153,  -153,  -153,   176,   138,   168,
     176,    83,    83,   177,    97,  -153,    83,  -153,   154,  -153,
      83,  -153,    24,    83,    83,  -153,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,    83,    83,  -153,  -153,    83,     0,    10,
      10,  -153,    10,    10,   116,    68,    83,   178,     9,  -153,
     178,   135,   148,   179,   173,    83,    83,    62,    83,    63,
    -153,   130,  -153,   174,   162,  -153,  -153,   170,   170,  -153,
    -153,  -153,    61,   180,   174,    83,    45,   181,   182,   183,
       9,  -153,    55,   175,     9,    95,    26,  -153,   200,  -153,
    -153,    83,   142,   184,  -153,   185,  -153,  -153,   144,    83,
      87,    87,    87,   186,  -153,    28,  -153,    26,   155,  -153,
      83,   148,  -153,  -153,  -153,  -153,   187,    92,   189,  -153,
     148,   190,   188,   191,  -153,  -153,  -153,    47,   192,    83,
      26,    26,    83,    87,  -153,  -153,   148,   207,  -153,   193,
    -153,    26,    87,  -153,   195,    26,  -153
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,     0,     0,    36,    37,     0,     0,     2,     5,     7,
       0,     0,    29,    30,    31,     0,    54,     0,    52,    10,
       0,     0,     1,     4,    13,     6,    28,    54,     0,     0,
       0,    55,     0,    35,    38,     0,     0,     0,     0,    12,
      15,     0,    34,   112,   103,     0,     0,     0,    56,    76,
      78,    80,    93,    97,   109,    50,     0,     0,    46,    49,
       0,    54,    53,    41,     0,    33,    32,    17,     0,     0,
      16,     0,    89,   113,   112,   105,     0,   111,   112,   104,
       0,   110,     0,     0,     0,    82,    85,    86,    87,    83,
      84,    94,    95,     0,     0,    98,    99,     0,     0,     0,
       0,    42,     0,     0,     0,    39,    23,    19,    27,    14,
      18,     0,    91,     0,    88,     0,    89,     0,    89,     0,
     100,    77,    79,    81,    92,    96,    51,    44,    45,    47,
      48,    43,    40,     0,    22,     0,   112,     0,     0,     0,
      27,    66,     0,     0,    26,     0,    25,    58,     0,   115,
     106,     0,     0,     0,   102,     0,   101,    20,     0,    89,
       0,     0,    70,     0,    67,     0,     8,    24,   112,    57,
       0,    90,   114,   108,   107,    21,     0,   112,     0,    73,
      75,     0,     0,    69,    72,    59,    68,     0,     0,     0,
       0,     0,    89,     0,    62,    65,    74,    63,    60,     0,
      71,     0,    70,    64,     0,     0,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -153,  -153,  -153,   214,   212,  -153,  -153,  -153,   159,   161,
    -153,    89,   -95,    -7,  -153,  -153,    -2,   209,   -27,   120,
     100,    99,   -10,   201,    90,  -135,    30,  -153,    74,  -152,
     -29,   157,   163,  -153,  -110,  -153,   -62,  -153,   143,  -153,
     139,   -44,  -153
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,     9,    10,    38,    39,    40,   107,
     133,   143,    11,    12,    13,    14,    15,    35,    31,    57,
      58,    59,    17,    18,   146,   147,   182,   183,   178,   179,
     112,    49,    50,    93,   113,   114,    51,    94,    52,    97,
      53,    54,    73
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    77,    81,    21,    26,    28,   153,    63,   155,   111,
     184,   169,   136,   144,    55,     3,     4,   137,    82,   138,
     139,     5,    41,    99,   100,    16,    74,    75,    19,   168,
     126,   123,   169,    71,   137,    72,   138,   139,    83,    56,
     140,   200,    83,   141,   134,   144,   142,   117,    61,   176,
     184,   119,    76,   152,   120,   197,   198,   140,    43,    44,
     141,    83,   186,   142,   148,    24,   203,    41,    78,    79,
     206,    45,    71,   158,   159,    22,    83,    83,   132,    46,
      27,   194,   199,    29,    47,    34,    43,    44,    60,   164,
     177,    44,   154,   156,    80,    30,   148,    30,    61,    45,
     148,    29,   148,    45,    29,   189,   145,    46,    67,    99,
     100,    46,    47,   165,   101,    30,    47,   -11,    30,    71,
      -9,    72,   171,   148,    71,     1,   116,     2,     3,     4,
      70,   180,   180,   180,     5,    28,    68,    26,   145,    99,
     100,   187,   145,    69,   131,    84,   148,   148,    85,    86,
      87,    88,    89,    90,    91,    92,   105,   148,    91,    92,
     196,   148,    83,   149,   180,    91,    92,    91,    92,   108,
     172,    37,   175,   180,     3,     4,    98,    20,     3,     4,
     104,    71,    71,   118,   159,    32,    33,    95,    96,    32,
      42,    64,    65,    64,    66,   102,   103,    91,    92,   127,
     128,   129,   130,   106,   115,   135,   151,   166,   157,   150,
     160,   161,   162,   170,   173,   174,   201,   188,   185,   190,
     191,    23,   192,    25,   193,   205,   195,   202,   109,   163,
      36,   110,   204,    62,   167,   181,   125,   124,     0,     0,
     121,     0,     0,     0,     0,     0,     0,   122
};

static const yytype_int16 yycheck[] =
{
      29,    45,    46,     5,    11,    15,   116,    34,   118,    71,
     162,   146,     3,   108,     4,     6,     7,     8,    47,    10,
      11,    12,    24,    23,    24,     3,     3,     4,     3,     3,
      30,    93,   167,    27,     8,    29,    10,    11,    14,    29,
      31,   193,    14,    34,   106,   140,    37,    76,     3,   159,
     202,    80,    29,   115,    30,   190,   191,    31,     3,     4,
      34,    14,    34,    37,   108,    29,   201,    69,     3,     4,
     205,    16,    27,   135,    29,     0,    14,    14,   105,    24,
       3,    34,   192,    13,    29,     3,     3,     4,    27,    34,
       3,     4,    30,    30,    29,    27,   140,    27,     3,    16,
     144,    13,   146,    16,    13,    13,   108,    24,     3,    23,
      24,    24,    29,   142,    28,    27,    29,    29,    27,    27,
      29,    29,   151,   167,    27,     3,    29,     5,     6,     7,
       3,   160,   161,   162,    12,   145,    30,   144,   140,    23,
      24,   170,   144,    33,    28,    15,   190,   191,    17,    18,
      19,    20,    21,    22,    23,    24,     3,   201,    23,    24,
     189,   205,    14,    28,   193,    23,    24,    23,    24,    31,
      28,     3,    28,   202,     6,     7,    56,     5,     6,     7,
      60,    27,    27,    29,    29,    33,    34,    25,    26,    33,
      34,    33,    34,    33,    34,    25,    26,    23,    24,    99,
     100,   102,   103,    27,    27,    27,    33,    32,    28,    30,
      29,    29,    29,    13,    30,    30,     9,    30,    32,    30,
      30,     7,    34,    11,    33,    30,    34,    34,    69,   140,
      21,    70,   202,    32,   144,   161,    97,    94,    -1,    -1,
      83,    -1,    -1,    -1,    -1,    -1,    -1,    84
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     5,     6,     7,    12,    39,    40,    41,    42,
      43,    50,    51,    52,    53,    54,     3,    60,    61,     3,
       5,    54,     0,    41,    29,    42,    51,     3,    60,    13,
      27,    56,    33,    34,     3,    55,    55,     3,    44,    45,
      46,    54,    34,     3,     4,    16,    24,    29,    68,    69,
      70,    74,    76,    78,    79,     4,    29,    57,    58,    59,
      27,     3,    61,    56,    33,    34,    34,     3,    30,    33,
       3,    27,    29,    80,     3,     4,    29,    79,     3,     4,
      29,    79,    68,    14,    15,    17,    18,    19,    20,    21,
      22,    23,    24,    71,    75,    25,    26,    77,    57,    23,
      24,    28,    25,    26,    57,     3,    27,    47,    31,    46,
      47,    74,    68,    72,    73,    27,    29,    68,    29,    68,
      30,    69,    70,    74,    76,    78,    30,    58,    58,    59,
      59,    28,    56,    48,    74,    27,     3,     8,    10,    11,
      31,    34,    37,    49,    50,    54,    62,    63,    79,    28,
      30,    33,    74,    72,    30,    72,    30,    28,    74,    29,
      29,    29,    29,    49,    34,    68,    32,    62,     3,    63,
      13,    68,    28,    30,    30,    28,    72,     3,    66,    67,
      68,    66,    64,    65,    67,    32,    34,    68,    30,    13,
      30,    30,    34,    33,    34,    34,    68,    63,    63,    72,
      67,     9,    34,    63,    64,    30,    63
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    38,    39,    39,    40,    40,    41,    41,    42,    43,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46,
      47,    47,    48,    48,    49,    49,    49,    49,    50,    50,
      51,    51,    52,    52,    53,    53,    54,    54,    55,    55,
      55,    55,    56,    56,    57,    57,    57,    58,    58,    58,
      59,    59,    60,    60,    61,    61,    61,    62,    62,    63,
      63,    63,    63,    63,    63,    63,    63,    63,    63,    64,
      64,    65,    65,    66,    67,    67,    68,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    72,    72,
      73,    73,    74,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    79,    79,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     2,     1,     2,     1,     7,     2,
       2,     2,     1,     0,     3,     1,     2,     2,     3,     3,
       3,     4,     1,     0,     2,     1,     1,     0,     2,     1,
       1,     1,     4,     4,     3,     3,     1,     1,     1,     3,
       4,     2,     3,     4,     3,     3,     1,     3,     3,     1,
       1,     3,     1,     3,     1,     2,     3,     2,     1,     3,
       5,     9,     4,     5,     7,     5,     1,     2,     3,     1,
       0,     3,     1,     1,     3,     1,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     4,     4,     1,     2,     2,     4,     5,     5,     1,
       2,     2,     1,     2,     4,     3
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
  YY_USE (yykind);
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
  case 2: /* program: global_decl_list  */
#line 166 "parser.y"
                                   { (yyval.node)=Allocate(PROGRAM_NODE);  makeChild((yyval.node),(yyvsp[0].node)); prog=(yyval.node);}
#line 1396 "parser.tab.c"
    break;

  case 3: /* program: %empty  */
#line 167 "parser.y"
                  { (yyval.node)=Allocate(PROGRAM_NODE); prog=(yyval.node);}
#line 1402 "parser.tab.c"
    break;

  case 4: /* global_decl_list: global_decl_list global_decl  */
#line 171 "parser.y"
                    {
                        (yyval.node) = makeSibling((yyvsp[-1].node), (yyvsp[0].node));
                    }
#line 1410 "parser.tab.c"
    break;

  case 5: /* global_decl_list: global_decl  */
#line 175 "parser.y"
                    {
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 1418 "parser.tab.c"
    break;

  case 6: /* global_decl: decl_list function_decl  */
#line 181 "parser.y"
                {
                    (yyval.node) = makeSibling(makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[-1].node)), (yyvsp[0].node));
                }
#line 1426 "parser.tab.c"
    break;

  case 7: /* global_decl: function_decl  */
#line 185 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1434 "parser.tab.c"
    break;

  case 8: /* function_decl: function_head MK_LPAREN opt_param_list MK_RPAREN MK_LBRACE block MK_RBRACE  */
#line 191 "parser.y"
                    {
                        (yyval.node) = (yyvsp[-6].node);
                        makeChild((yyval.node), (yyvsp[-4].node));
                        makeChild((yyval.node), (yyvsp[-1].node));
                    }
#line 1444 "parser.tab.c"
    break;

  case 9: /* function_head: type ID  */
#line 198 "parser.y"
                    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        makeFamily((yyval.node), 2, (yyvsp[-1].node), makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                    }
#line 1453 "parser.tab.c"
    break;

  case 10: /* function_head: VOID ID  */
#line 203 "parser.y"
                    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* voidNode = makeIDNode("void", NORMAL_ID);
                        makeFamily((yyval.node), 2, voidNode, makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                    }
#line 1463 "parser.tab.c"
    break;

  case 11: /* function_head: ID ID  */
#line 209 "parser.y"
                    {
                        (yyval.node) = makeDeclNode(FUNCTION_DECL);
                        AST_NODE* idNode = makeIDNode((yyvsp[-1].lexeme), NORMAL_ID);
                        makeFamily((yyval.node), 2, idNode, makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                    }
#line 1473 "parser.tab.c"
    break;

  case 12: /* opt_param_list: param_list  */
#line 216 "parser.y"
                    {
                        (yyval.node) = Allocate(PARAM_LIST_NODE);
                        makeChild((yyval.node), (yyvsp[0].node));
                    }
#line 1482 "parser.tab.c"
    break;

  case 13: /* opt_param_list: %empty  */
#line 221 "parser.y"
                    {
                        (yyval.node) = Allocate(PARAM_LIST_NODE);
                    }
#line 1490 "parser.tab.c"
    break;

  case 14: /* param_list: param_list MK_COMMA param  */
#line 227 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1498 "parser.tab.c"
    break;

  case 15: /* param_list: param  */
#line 231 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1506 "parser.tab.c"
    break;

  case 16: /* param: type ID  */
#line 237 "parser.y"
                {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
                    makeFamily((yyval.node), 2, (yyvsp[-1].node), makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                }
#line 1515 "parser.tab.c"
    break;

  case 17: /* param: ID ID  */
#line 242 "parser.y"
                {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
                    makeFamily((yyval.node), 2, makeIDNode((yyvsp[-1].lexeme), NORMAL_ID), makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                }
#line 1524 "parser.tab.c"
    break;

  case 18: /* param: type ID dim_fn  */
#line 247 "parser.y"
                {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), makeChild(makeIDNode((yyvsp[-1].lexeme), ARRAY_ID), (yyvsp[0].node)));
                }
#line 1533 "parser.tab.c"
    break;

  case 19: /* param: ID ID dim_fn  */
#line 252 "parser.y"
                {
                    (yyval.node) = makeDeclNode(FUNCTION_PARAMETER_DECL);
                    makeFamily((yyval.node), 2, makeIDNode((yyvsp[-2].lexeme), NORMAL_ID), makeChild(makeIDNode((yyvsp[-1].lexeme), ARRAY_ID), (yyvsp[0].node)));
                }
#line 1542 "parser.tab.c"
    break;

  case 20: /* dim_fn: MK_LB expr_null MK_RB  */
#line 258 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1550 "parser.tab.c"
    break;

  case 21: /* dim_fn: dim_fn MK_LB expr MK_RB  */
#line 262 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-3].node), (yyvsp[-1].node));
                }
#line 1558 "parser.tab.c"
    break;

  case 22: /* expr_null: expr  */
#line 268 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1566 "parser.tab.c"
    break;

  case 23: /* expr_null: %empty  */
#line 272 "parser.y"
                {
                    (yyval.node) = Allocate(NUL_NODE);
                }
#line 1574 "parser.tab.c"
    break;

  case 24: /* block: decl_list stmt_list  */
#line 278 "parser.y"
                    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeFamily((yyval.node), 2, makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[-1].node)), makeChild(Allocate(STMT_LIST_NODE), (yyvsp[0].node)));
                    }
#line 1583 "parser.tab.c"
    break;

  case 25: /* block: stmt_list  */
#line 283 "parser.y"
                    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeChild((yyval.node), makeChild(Allocate(STMT_LIST_NODE), (yyvsp[0].node)));
                    }
#line 1592 "parser.tab.c"
    break;

  case 26: /* block: decl_list  */
#line 288 "parser.y"
                    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                        makeChild((yyval.node), makeChild(Allocate(VARIABLE_DECL_LIST_NODE), (yyvsp[0].node)));
                    }
#line 1601 "parser.tab.c"
    break;

  case 27: /* block: %empty  */
#line 292 "parser.y"
                    {
                        (yyval.node) = Allocate(BLOCK_NODE);
                    }
#line 1609 "parser.tab.c"
    break;

  case 28: /* decl_list: decl_list decl  */
#line 298 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1617 "parser.tab.c"
    break;

  case 29: /* decl_list: decl  */
#line 302 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1625 "parser.tab.c"
    break;

  case 30: /* decl: type_decl  */
#line 308 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1633 "parser.tab.c"
    break;

  case 31: /* decl: var_decl  */
#line 312 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1641 "parser.tab.c"
    break;

  case 32: /* type_decl: TYPEDEF type id_list MK_SEMICOLON  */
#line 318 "parser.y"
                {
                    (yyval.node) = makeDeclNode(TYPE_DECL);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[-1].node));
                }
#line 1650 "parser.tab.c"
    break;

  case 33: /* type_decl: TYPEDEF VOID id_list MK_SEMICOLON  */
#line 323 "parser.y"
                {
                    (yyval.node) = makeDeclNode(TYPE_DECL);
                    AST_NODE* voidNode = makeIDNode("void", NORMAL_ID);
                    makeFamily((yyval.node), 2, voidNode, (yyvsp[-1].node));
                }
#line 1660 "parser.tab.c"
    break;

  case 34: /* var_decl: type init_id_list MK_SEMICOLON  */
#line 331 "parser.y"
                {
                    (yyval.node) = makeDeclNode(VARIABLE_DECL);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[-1].node));
                }
#line 1669 "parser.tab.c"
    break;

  case 35: /* var_decl: ID init_id_list MK_SEMICOLON  */
#line 336 "parser.y"
                {
                    (yyval.node) = makeDeclNode(VARIABLE_DECL);
                    makeFamily((yyval.node), 2, makeIDNode((yyvsp[-2].lexeme), NORMAL_ID), (yyvsp[-1].node));
                }
#line 1678 "parser.tab.c"
    break;

  case 36: /* type: INT  */
#line 343 "parser.y"
                {
                    (yyval.node) = makeIDNode("int", NORMAL_ID);
                }
#line 1686 "parser.tab.c"
    break;

  case 37: /* type: FLOAT  */
#line 347 "parser.y"
                {
                    (yyval.node) = makeIDNode("float", NORMAL_ID);
                }
#line 1694 "parser.tab.c"
    break;

  case 38: /* id_list: ID  */
#line 353 "parser.y"
                {
                    (yyval.node) = makeIDNode((yyvsp[0].lexeme), NORMAL_ID);
                }
#line 1702 "parser.tab.c"
    break;

  case 39: /* id_list: id_list MK_COMMA ID  */
#line 357 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-2].node), makeIDNode((yyvsp[0].lexeme), NORMAL_ID));
                }
#line 1710 "parser.tab.c"
    break;

  case 40: /* id_list: id_list MK_COMMA ID dim_decl  */
#line 361 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-3].node), makeChild(makeIDNode((yyvsp[-1].lexeme), ARRAY_ID), (yyvsp[0].node)));
                }
#line 1718 "parser.tab.c"
    break;

  case 41: /* id_list: ID dim_decl  */
#line 365 "parser.y"
                {
                    (yyval.node) = makeChild(makeIDNode((yyvsp[-1].lexeme), ARRAY_ID), (yyvsp[0].node));
                }
#line 1726 "parser.tab.c"
    break;

  case 42: /* dim_decl: MK_LB cexpr MK_RB  */
#line 370 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1734 "parser.tab.c"
    break;

  case 43: /* dim_decl: dim_decl MK_LB cexpr MK_RB  */
#line 374 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-3].node), (yyvsp[-1].node));
                }
#line 1742 "parser.tab.c"
    break;

  case 44: /* cexpr: cexpr OP_PLUS mcexpr  */
#line 379 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_ADD);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1751 "parser.tab.c"
    break;

  case 45: /* cexpr: cexpr OP_MINUS mcexpr  */
#line 384 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_SUB);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1760 "parser.tab.c"
    break;

  case 46: /* cexpr: mcexpr  */
#line 389 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1768 "parser.tab.c"
    break;

  case 47: /* mcexpr: mcexpr OP_TIMES cfactor  */
#line 394 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_MUL);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1777 "parser.tab.c"
    break;

  case 48: /* mcexpr: mcexpr OP_DIVIDE cfactor  */
#line 399 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_DIV);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1786 "parser.tab.c"
    break;

  case 49: /* mcexpr: cfactor  */
#line 404 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1794 "parser.tab.c"
    break;

  case 50: /* cfactor: CONST  */
#line 410 "parser.y"
                {
                    (yyval.node) = Allocate(CONST_VALUE_NODE);
                    (yyval.node)->semantic_value.const1 = (yyvsp[0].const1);
                }
#line 1803 "parser.tab.c"
    break;

  case 51: /* cfactor: MK_LPAREN cexpr MK_RPAREN  */
#line 415 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1811 "parser.tab.c"
    break;

  case 52: /* init_id_list: init_id  */
#line 421 "parser.y"
                    {
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 1819 "parser.tab.c"
    break;

  case 53: /* init_id_list: init_id_list MK_COMMA init_id  */
#line 425 "parser.y"
                    {
                        (yyval.node) = makeSibling((yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 1827 "parser.tab.c"
    break;

  case 54: /* init_id: ID  */
#line 431 "parser.y"
                {
                    (yyval.node) = makeIDNode((yyvsp[0].lexeme), NORMAL_ID);
                }
#line 1835 "parser.tab.c"
    break;

  case 55: /* init_id: ID dim_decl  */
#line 435 "parser.y"
                {
                    (yyval.node) = makeChild(makeIDNode((yyvsp[-1].lexeme), ARRAY_ID), (yyvsp[0].node));
                }
#line 1843 "parser.tab.c"
    break;

  case 56: /* init_id: ID OP_ASSIGN relop_expr  */
#line 439 "parser.y"
                {
                    (yyval.node) = makeChild(makeIDNode((yyvsp[-2].lexeme), WITH_INIT_ID), (yyvsp[0].node));
                }
#line 1851 "parser.tab.c"
    break;

  case 57: /* stmt_list: stmt_list stmt  */
#line 445 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-1].node), (yyvsp[0].node));
                }
#line 1859 "parser.tab.c"
    break;

  case 58: /* stmt_list: stmt  */
#line 449 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1867 "parser.tab.c"
    break;

  case 59: /* stmt: MK_LBRACE block MK_RBRACE  */
#line 457 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 1875 "parser.tab.c"
    break;

  case 60: /* stmt: WHILE MK_LPAREN test MK_RPAREN stmt  */
#line 461 "parser.y"
                {
                    (yyval.node) = makeStmtNode(WHILE_STMT);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1884 "parser.tab.c"
    break;

  case 61: /* stmt: FOR MK_LPAREN assign_expr_list MK_SEMICOLON relop_expr_list MK_SEMICOLON assign_expr_list MK_RPAREN stmt  */
#line 466 "parser.y"
                {
                    (yyval.node) = makeStmtNode(FOR_STMT);
                    makeFamily((yyval.node), 4, (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1893 "parser.tab.c"
    break;

  case 62: /* stmt: var_ref OP_ASSIGN relop_expr MK_SEMICOLON  */
#line 471 "parser.y"
                {
                    (yyval.node) = makeStmtNode(ASSIGN_STMT);
                    makeFamily((yyval.node), 2, (yyvsp[-3].node), (yyvsp[-1].node));
                }
#line 1902 "parser.tab.c"
    break;

  case 63: /* stmt: IF MK_LPAREN test MK_RPAREN stmt  */
#line 476 "parser.y"
                {
                    (yyval.node) = makeStmtNode(IF_STMT);
                    makeFamily((yyval.node), 3, (yyvsp[-2].node), (yyvsp[0].node), Allocate(NUL_NODE));
                }
#line 1911 "parser.tab.c"
    break;

  case 64: /* stmt: IF MK_LPAREN test MK_RPAREN stmt ELSE stmt  */
#line 481 "parser.y"
                {
                    (yyval.node) = makeStmtNode(IF_STMT);
                    makeFamily((yyval.node), 3, (yyvsp[-4].node), (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 1920 "parser.tab.c"
    break;

  case 65: /* stmt: ID MK_LPAREN relop_expr_list MK_RPAREN MK_SEMICOLON  */
#line 486 "parser.y"
                {
                    (yyval.node) = makeStmtNode(FUNCTION_CALL_STMT);
                    makeFamily((yyval.node), 2, makeIDNode((yyvsp[-4].lexeme), NORMAL_ID), (yyvsp[-2].node));
                }
#line 1929 "parser.tab.c"
    break;

  case 66: /* stmt: MK_SEMICOLON  */
#line 491 "parser.y"
                {
                    (yyval.node) = Allocate(NUL_NODE);
                }
#line 1937 "parser.tab.c"
    break;

  case 67: /* stmt: RETURN MK_SEMICOLON  */
#line 495 "parser.y"
                {
                    (yyval.node) = makeStmtNode(RETURN_STMT);
                    makeChild((yyval.node), Allocate(NUL_NODE));
                }
#line 1946 "parser.tab.c"
    break;

  case 68: /* stmt: RETURN relop_expr MK_SEMICOLON  */
#line 500 "parser.y"
                {
                    (yyval.node) = makeStmtNode(RETURN_STMT);
                    makeChild((yyval.node), (yyvsp[-1].node));
                }
#line 1955 "parser.tab.c"
    break;

  case 69: /* assign_expr_list: nonempty_assign_expr_list  */
#line 507 "parser.y"
                     {
                        (yyval.node) = makeChild(Allocate(NONEMPTY_ASSIGN_EXPR_LIST_NODE), (yyvsp[0].node));
                     }
#line 1963 "parser.tab.c"
    break;

  case 70: /* assign_expr_list: %empty  */
#line 511 "parser.y"
                     {
                         (yyval.node) = Allocate(NUL_NODE);
                     }
#line 1971 "parser.tab.c"
    break;

  case 71: /* nonempty_assign_expr_list: nonempty_assign_expr_list MK_COMMA assign_expr  */
#line 517 "parser.y"
                                    {
                                        (yyval.node) = makeSibling((yyvsp[-2].node), (yyvsp[0].node));
                                    }
#line 1979 "parser.tab.c"
    break;

  case 72: /* nonempty_assign_expr_list: assign_expr  */
#line 521 "parser.y"
                                    {
                                        (yyval.node) = (yyvsp[0].node);
                                    }
#line 1987 "parser.tab.c"
    break;

  case 73: /* test: assign_expr  */
#line 527 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 1995 "parser.tab.c"
    break;

  case 74: /* assign_expr: ID OP_ASSIGN relop_expr  */
#line 533 "parser.y"
                    {
                        //TODO: for simpler implementation, use ASSIGN_STMT for now
                        (yyval.node) = makeStmtNode(ASSIGN_STMT);
                        makeFamily((yyval.node), 2, makeIDNode((yyvsp[-2].lexeme), NORMAL_ID), (yyvsp[0].node));
                    }
#line 2005 "parser.tab.c"
    break;

  case 75: /* assign_expr: relop_expr  */
#line 539 "parser.y"
                    {
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 2013 "parser.tab.c"
    break;

  case 76: /* relop_expr: relop_term  */
#line 545 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2021 "parser.tab.c"
    break;

  case 77: /* relop_expr: relop_expr OP_OR relop_term  */
#line 549 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_OR);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 2030 "parser.tab.c"
    break;

  case 78: /* relop_term: relop_factor  */
#line 556 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2038 "parser.tab.c"
    break;

  case 79: /* relop_term: relop_term OP_AND relop_factor  */
#line 560 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_AND);
                    makeFamily((yyval.node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 2047 "parser.tab.c"
    break;

  case 80: /* relop_factor: expr  */
#line 567 "parser.y"
                    {
                        (yyval.node) = (yyvsp[0].node);
                    }
#line 2055 "parser.tab.c"
    break;

  case 81: /* relop_factor: expr rel_op expr  */
#line 571 "parser.y"
                    {
                        (yyval.node) = makeFamily((yyvsp[-1].node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                    }
#line 2063 "parser.tab.c"
    break;

  case 82: /* rel_op: OP_EQ  */
#line 577 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_EQ);
                }
#line 2071 "parser.tab.c"
    break;

  case 83: /* rel_op: OP_GE  */
#line 581 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_GE);
                }
#line 2079 "parser.tab.c"
    break;

  case 84: /* rel_op: OP_LE  */
#line 585 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_LE);
                }
#line 2087 "parser.tab.c"
    break;

  case 85: /* rel_op: OP_NE  */
#line 589 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_NE);
                }
#line 2095 "parser.tab.c"
    break;

  case 86: /* rel_op: OP_GT  */
#line 593 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_GT);
                }
#line 2103 "parser.tab.c"
    break;

  case 87: /* rel_op: OP_LT  */
#line 597 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_LT);
                }
#line 2111 "parser.tab.c"
    break;

  case 88: /* relop_expr_list: nonempty_relop_expr_list  */
#line 604 "parser.y"
                    {
                        (yyval.node) = makeChild(Allocate(NONEMPTY_RELOP_EXPR_LIST_NODE), (yyvsp[0].node));
                    }
#line 2119 "parser.tab.c"
    break;

  case 89: /* relop_expr_list: %empty  */
#line 608 "parser.y"
                    {
                        (yyval.node) = Allocate(NUL_NODE);
                    }
#line 2127 "parser.tab.c"
    break;

  case 90: /* nonempty_relop_expr_list: nonempty_relop_expr_list MK_COMMA relop_expr  */
#line 614 "parser.y"
                                {
                                    (yyval.node) = makeSibling((yyvsp[-2].node), (yyvsp[0].node));
                                }
#line 2135 "parser.tab.c"
    break;

  case 91: /* nonempty_relop_expr_list: relop_expr  */
#line 618 "parser.y"
                                {
                                    (yyval.node) = (yyvsp[0].node);
                                }
#line 2143 "parser.tab.c"
    break;

  case 92: /* expr: expr add_op term  */
#line 624 "parser.y"
                {
                    (yyval.node) = makeFamily((yyvsp[-1].node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 2151 "parser.tab.c"
    break;

  case 93: /* expr: term  */
#line 628 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2159 "parser.tab.c"
    break;

  case 94: /* add_op: OP_PLUS  */
#line 634 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_ADD);
                }
#line 2167 "parser.tab.c"
    break;

  case 95: /* add_op: OP_MINUS  */
#line 638 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_SUB);
                }
#line 2175 "parser.tab.c"
    break;

  case 96: /* term: term mul_op factor  */
#line 644 "parser.y"
                {
                    (yyval.node) = makeFamily((yyvsp[-1].node), 2, (yyvsp[-2].node), (yyvsp[0].node));
                }
#line 2183 "parser.tab.c"
    break;

  case 97: /* term: factor  */
#line 648 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2191 "parser.tab.c"
    break;

  case 98: /* mul_op: OP_TIMES  */
#line 654 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_MUL);
                }
#line 2199 "parser.tab.c"
    break;

  case 99: /* mul_op: OP_DIVIDE  */
#line 658 "parser.y"
                {
                    (yyval.node) = makeExprNode(BINARY_OPERATION, BINARY_OP_DIV);
                }
#line 2207 "parser.tab.c"
    break;

  case 100: /* factor: MK_LPAREN relop_expr MK_RPAREN  */
#line 664 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 2215 "parser.tab.c"
    break;

  case 101: /* factor: OP_MINUS MK_LPAREN relop_expr MK_RPAREN  */
#line 668 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
                    makeChild((yyval.node), (yyvsp[-1].node));
                }
#line 2224 "parser.tab.c"
    break;

  case 102: /* factor: OP_NOT MK_LPAREN relop_expr MK_RPAREN  */
#line 673 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_LOGICAL_NEGATION);
                    makeChild((yyval.node), (yyvsp[-1].node));
                }
#line 2233 "parser.tab.c"
    break;

  case 103: /* factor: CONST  */
#line 678 "parser.y"
                {
                    (yyval.node) = Allocate(CONST_VALUE_NODE);
                    (yyval.node)->semantic_value.const1=(yyvsp[0].const1);
                }
#line 2242 "parser.tab.c"
    break;

  case 104: /* factor: OP_MINUS CONST  */
#line 683 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
                    AST_NODE *constNode = Allocate(CONST_VALUE_NODE);
                    constNode->semantic_value.const1 = (yyvsp[0].const1);
                    makeChild((yyval.node), constNode);
                }
#line 2253 "parser.tab.c"
    break;

  case 105: /* factor: OP_NOT CONST  */
#line 690 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_LOGICAL_NEGATION);
                    AST_NODE *constNode = Allocate(CONST_VALUE_NODE);
                    constNode->semantic_value.const1 = (yyvsp[0].const1);
                    makeChild((yyval.node), constNode);
                }
#line 2264 "parser.tab.c"
    break;

  case 106: /* factor: ID MK_LPAREN relop_expr_list MK_RPAREN  */
#line 697 "parser.y"
                {
                    (yyval.node) = makeStmtNode(FUNCTION_CALL_STMT);
                    makeFamily((yyval.node), 2, makeIDNode((yyvsp[-3].lexeme), NORMAL_ID), (yyvsp[-1].node));
                }
#line 2273 "parser.tab.c"
    break;

  case 107: /* factor: OP_MINUS ID MK_LPAREN relop_expr_list MK_RPAREN  */
#line 702 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
                    AST_NODE* functionCallNode = makeStmtNode(FUNCTION_CALL_STMT);
                    makeFamily(functionCallNode, 2, makeIDNode((yyvsp[-3].lexeme), NORMAL_ID), (yyvsp[-1].node));
                    makeChild((yyval.node), functionCallNode);
                }
#line 2284 "parser.tab.c"
    break;

  case 108: /* factor: OP_NOT ID MK_LPAREN relop_expr_list MK_RPAREN  */
#line 709 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_LOGICAL_NEGATION);
                    AST_NODE* functionCallNode = makeStmtNode(FUNCTION_CALL_STMT);
                    makeFamily(functionCallNode, 2, makeIDNode((yyvsp[-3].lexeme), NORMAL_ID), (yyvsp[-1].node));
                    makeChild((yyval.node), functionCallNode);
                }
#line 2295 "parser.tab.c"
    break;

  case 109: /* factor: var_ref  */
#line 716 "parser.y"
                {
                    (yyval.node) = (yyvsp[0].node);
                }
#line 2303 "parser.tab.c"
    break;

  case 110: /* factor: OP_MINUS var_ref  */
#line 720 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_NEGATIVE);
                    makeChild((yyval.node), (yyvsp[0].node));
                }
#line 2312 "parser.tab.c"
    break;

  case 111: /* factor: OP_NOT var_ref  */
#line 725 "parser.y"
                {
                    (yyval.node) = makeExprNode(UNARY_OPERATION, UNARY_OP_LOGICAL_NEGATION);
                    makeChild((yyval.node), (yyvsp[0].node));
                }
#line 2321 "parser.tab.c"
    break;

  case 112: /* var_ref: ID  */
#line 732 "parser.y"
                {
                    (yyval.node) = makeIDNode((yyvsp[0].lexeme), NORMAL_ID);
                }
#line 2329 "parser.tab.c"
    break;

  case 113: /* var_ref: ID dim_list  */
#line 736 "parser.y"
                {
                    (yyval.node) = makeIDNode((yyvsp[-1].lexeme), ARRAY_ID);
                    makeChild((yyval.node),(yyvsp[0].node));
                }
#line 2338 "parser.tab.c"
    break;

  case 114: /* dim_list: dim_list MK_LB expr MK_RB  */
#line 744 "parser.y"
                {
                    (yyval.node) = makeSibling((yyvsp[-3].node), (yyvsp[-1].node));
                }
#line 2346 "parser.tab.c"
    break;

  case 115: /* dim_list: MK_LB expr MK_RB  */
#line 748 "parser.y"
                {
                    (yyval.node) = (yyvsp[-1].node);
                }
#line 2354 "parser.tab.c"
    break;


#line 2358 "parser.tab.c"

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

#line 754 "parser.y"


#include "lex.yy.c"
main (argc, argv)
int argc;
char *argv[];
  {
     yyin = fopen(argv[1],"r");
     yyparse();
     // printGV(prog, NULL);

     initializeSymbolTable();

     semanticAnalysis(prog);

     symbolTableEnd();
     if (!g_anyErrorOccur) {
        printf("Parsing completed. No errors found.\n");
     }
  } /* main */


int yyerror (mesg)
char *mesg;
  {
  printf("%s\t%d\t%s\t%s\n", "Error found in Line ", linenumber, "next token: ", yytext );
  exit(1);
  }
