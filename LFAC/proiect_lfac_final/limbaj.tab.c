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
#line 1 "limbaj.y"

    #include <iostream>
    #include <vector>
    #include <string>
    #include<cstring>
    #include "SymTable.h"
    #include "functii.h"
    #include "ast.h"

        using namespace std;
        extern FILE* yyin;
        extern char* yytext;
        extern int yylineno;
        extern int yylex();

        class SymTable* global;
        class SymTable* current;
        int errorCount = 0;

        vector<variabile>param;
        vector<variabile>param_value;



        

#line 98 "limbaj.tab.c"

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

#include "limbaj.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BGIN = 3,                       /* BGIN  */
  YYSYMBOL_END = 4,                        /* END  */
  YYSYMBOL_NR = 5,                         /* NR  */
  YYSYMBOL_IF = 6,                         /* IF  */
  YYSYMBOL_ELSE = 7,                       /* ELSE  */
  YYSYMBOL_FOR = 8,                        /* FOR  */
  YYSYMBOL_WHILE = 9,                      /* WHILE  */
  YYSYMBOL_PRINT = 10,                     /* PRINT  */
  YYSYMBOL_CLASS = 11,                     /* CLASS  */
  YYSYMBOL_ACCESS = 12,                    /* ACCESS  */
  YYSYMBOL_EQUAL = 13,                     /* EQUAL  */
  YYSYMBOL_ELIF = 14,                      /* ELIF  */
  YYSYMBOL_NEQ = 15,                       /* NEQ  */
  YYSYMBOL_LEQ = 16,                       /* LEQ  */
  YYSYMBOL_GEQ = 17,                       /* GEQ  */
  YYSYMBOL_AND = 18,                       /* AND  */
  YYSYMBOL_OR = 19,                        /* OR  */
  YYSYMBOL_NUME = 20,                      /* NUME  */
  YYSYMBOL_TIP = 21,                       /* TIP  */
  YYSYMBOL_RETURN = 22,                    /* RETURN  */
  YYSYMBOL_STRING = 23,                    /* STRING  */
  YYSYMBOL_BOOL = 24,                      /* BOOL  */
  YYSYMBOL_INTEGER = 25,                   /* INTEGER  */
  YYSYMBOL_FLOAT = 26,                     /* FLOAT  */
  YYSYMBOL_CHAR = 27,                      /* CHAR  */
  YYSYMBOL_VOID = 28,                      /* VOID  */
  YYSYMBOL_TYPEOF = 29,                    /* TYPEOF  */
  YYSYMBOL_30_ = 30,                       /* '!'  */
  YYSYMBOL_31_ = 31,                       /* '<'  */
  YYSYMBOL_32_ = 32,                       /* '>'  */
  YYSYMBOL_33_ = 33,                       /* '+'  */
  YYSYMBOL_34_ = 34,                       /* '-'  */
  YYSYMBOL_35_ = 35,                       /* '*'  */
  YYSYMBOL_36_ = 36,                       /* '/'  */
  YYSYMBOL_37_ = 37,                       /* '%'  */
  YYSYMBOL_38_ = 38,                       /* ';'  */
  YYSYMBOL_39_ = 39,                       /* '['  */
  YYSYMBOL_40_ = 40,                       /* ']'  */
  YYSYMBOL_41_ = 41,                       /* '='  */
  YYSYMBOL_42_ = 42,                       /* '('  */
  YYSYMBOL_43_ = 43,                       /* ')'  */
  YYSYMBOL_44_ = 44,                       /* '{'  */
  YYSYMBOL_45_ = 45,                       /* '}'  */
  YYSYMBOL_46_ = 46,                       /* ','  */
  YYSYMBOL_47_ = 47,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_50_1 = 50,                      /* $@1  */
  YYSYMBOL_51_2 = 51,                      /* $@2  */
  YYSYMBOL_global_list = 52,               /* global_list  */
  YYSYMBOL_global = 53,                    /* global  */
  YYSYMBOL_declarare_variabile = 54,       /* declarare_variabile  */
  YYSYMBOL_declarare_functii = 55,         /* declarare_functii  */
  YYSYMBOL_56_3 = 56,                      /* $@3  */
  YYSYMBOL_57_4 = 57,                      /* $@4  */
  YYSYMBOL_58_5 = 58,                      /* $@5  */
  YYSYMBOL_list_param = 59,                /* list_param  */
  YYSYMBOL_corp_func = 60,                 /* corp_func  */
  YYSYMBOL_else_statement = 61,            /* else_statement  */
  YYSYMBOL_62_6 = 62,                      /* $@6  */
  YYSYMBOL_63_7 = 63,                      /* $@7  */
  YYSYMBOL_elif_statement = 64,            /* elif_statement  */
  YYSYMBOL_65_8 = 65,                      /* $@8  */
  YYSYMBOL_66_9 = 66,                      /* $@9  */
  YYSYMBOL_if_statement = 67,              /* if_statement  */
  YYSYMBOL_68_10 = 68,                     /* $@10  */
  YYSYMBOL_69_11 = 69,                     /* $@11  */
  YYSYMBOL_while_statement = 70,           /* while_statement  */
  YYSYMBOL_71_12 = 71,                     /* $@12  */
  YYSYMBOL_72_13 = 72,                     /* $@13  */
  YYSYMBOL_for_statement = 73,             /* for_statement  */
  YYSYMBOL_74_14 = 74,                     /* $@14  */
  YYSYMBOL_75_15 = 75,                     /* $@15  */
  YYSYMBOL_76_16 = 76,                     /* $@16  */
  YYSYMBOL_77_17 = 77,                     /* $@17  */
  YYSYMBOL_option = 78,                    /* option  */
  YYSYMBOL_block_de_cod = 79,              /* block_de_cod  */
  YYSYMBOL_apeluri = 80,                   /* apeluri  */
  YYSYMBOL_81_18 = 81,                     /* $@18  */
  YYSYMBOL_82_19 = 82,                     /* $@19  */
  YYSYMBOL_functii_predefinite = 83,       /* functii_predefinite  */
  YYSYMBOL_conditie = 84,                  /* conditie  */
  YYSYMBOL_conditie_logica = 85,           /* conditie_logica  */
  YYSYMBOL_comparatie = 86,                /* comparatie  */
  YYSYMBOL_expr = 87,                      /* expr  */
  YYSYMBOL_term = 88,                      /* term  */
  YYSYMBOL_factor = 89,                    /* factor  */
  YYSYMBOL_main = 90,                      /* main  */
  YYSYMBOL_clase = 91,                     /* clase  */
  YYSYMBOL_92_20 = 92,                     /* $@20  */
  YYSYMBOL_corp_clasa = 93,                /* corp_clasa  */
  YYSYMBOL_valoare = 94,                   /* valoare  */
  YYSYMBOL_95_21 = 95,                     /* $@21  */
  YYSYMBOL_96_22 = 96,                     /* $@22  */
  YYSYMBOL_param_val = 97                  /* param_val  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   317

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  50
/* YYNRULES -- Number of rules.  */
#define YYNRULES  116
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  269

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   284


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
       2,     2,     2,    30,     2,     2,     2,    37,     2,     2,
      42,    43,    35,    33,    46,    34,    47,    36,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
      31,    41,    32,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    39,     2,    40,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    44,     2,    45,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    65,    65,    70,    65,    87,    88,    93,    94,    95,
     100,   103,   106,   117,   131,   150,   160,   171,   157,   186,
     194,   193,   210,   213,   216,   219,   222,   227,   228,   230,
     237,   245,   236,   256,   262,   255,   271,   277,   270,   287,
     293,   286,   303,   327,   302,   333,   355,   332,   364,   366,
     368,   374,   376,   378,   380,   382,   384,   386,   391,   415,
     415,   482,   499,   527,   552,   552,   599,   600,   604,   611,
     619,   649,   655,   662,   675,   704,   738,   742,   746,   750,
     754,   758,   765,   797,   829,   838,   869,   900,   932,   941,
     952,   956,   966,   965,   983,   984,   985,   986,   987,   988,
     992,   997,  1002,  1007,  1012,  1017,  1059,  1059,  1139,  1139,
    1264,  1327,  1393,  1454,  1475,  1490,  1507
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
  "\"end of file\"", "error", "\"invalid token\"", "BGIN", "END", "NR",
  "IF", "ELSE", "FOR", "WHILE", "PRINT", "CLASS", "ACCESS", "EQUAL",
  "ELIF", "NEQ", "LEQ", "GEQ", "AND", "OR", "NUME", "TIP", "RETURN",
  "STRING", "BOOL", "INTEGER", "FLOAT", "CHAR", "VOID", "TYPEOF", "'!'",
  "'<'", "'>'", "'+'", "'-'", "'*'", "'/'", "'%'", "';'", "'['", "']'",
  "'='", "'('", "')'", "'{'", "'}'", "','", "'.'", "$accept", "program",
  "$@1", "$@2", "global_list", "global", "declarare_variabile",
  "declarare_functii", "$@3", "$@4", "$@5", "list_param", "corp_func",
  "else_statement", "$@6", "$@7", "elif_statement", "$@8", "$@9",
  "if_statement", "$@10", "$@11", "while_statement", "$@12", "$@13",
  "for_statement", "$@14", "$@15", "$@16", "$@17", "option",
  "block_de_cod", "apeluri", "$@18", "$@19", "functii_predefinite",
  "conditie", "conditie_logica", "comparatie", "expr", "term", "factor",
  "main", "clase", "$@20", "corp_clasa", "valoare", "$@21", "$@22",
  "param_val", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-162)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -162,     9,   195,  -162,    41,    49,    64,    87,    68,  -162,
    -162,  -162,  -162,     3,   175,   196,   -23,  -162,  -162,  -162,
    -162,  -162,   132,  -162,    84,   132,    91,    91,   119,   198,
      66,  -162,  -162,  -162,  -162,  -162,   132,   132,    76,  -162,
     160,   185,  -162,  -162,    80,    85,   113,   -11,    30,   100,
     129,   136,   143,    11,   141,   132,   153,  -162,    16,  -162,
    -162,  -162,   119,  -162,   194,   145,    -3,   198,   198,   198,
     191,    26,  -162,   219,   233,     2,   132,   132,   203,  -162,
    -162,  -162,  -162,  -162,  -162,   111,   111,   111,   111,   111,
     111,   208,  -162,   221,   107,   240,   224,   132,   236,   132,
     132,   238,   132,  -162,   244,   128,    92,   132,   222,   223,
    -162,  -162,  -162,  -162,  -162,   198,   198,  -162,  -162,  -162,
     229,   228,   230,   132,   227,  -162,  -162,   253,  -162,  -162,
    -162,   225,  -162,  -162,  -162,  -162,   247,  -162,  -162,   254,
    -162,   231,    21,   232,   256,    44,    63,   237,   125,   132,
     187,  -162,    74,  -162,   132,  -162,  -162,  -162,  -162,  -162,
     233,    75,  -162,   239,    28,   241,    28,   234,   132,   242,
     243,  -162,   245,  -162,   197,  -162,   132,  -162,  -162,   119,
      79,  -162,   132,   132,  -162,    28,   259,    28,   257,   246,
    -162,   146,   132,  -162,   132,   250,   161,   132,  -162,   248,
     233,   199,   262,   132,  -162,   249,  -162,   119,   132,   164,
     119,   169,  -162,  -162,   201,   251,  -162,  -162,   132,   171,
    -162,  -162,   179,   132,  -162,  -162,   252,  -162,   119,   186,
    -162,   255,   265,   193,   258,  -162,  -162,   260,   261,  -162,
     263,   273,  -162,   264,    28,  -162,   274,   266,  -162,  -162,
     268,   275,   132,   269,    81,   132,   267,    83,  -162,   270,
     119,  -162,  -162,   119,   271,  -162,  -162,   272,  -162
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       2,     0,     0,     1,     0,     0,     0,     0,     0,     5,
       7,     8,     9,     0,     0,     0,     0,     3,     6,    91,
      92,    13,     0,    10,     0,     0,    26,    26,    50,    99,
     105,   103,   104,   100,   101,   102,     0,     0,     0,    72,
      71,    84,    88,    89,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    52,    55,    56,
      57,    90,    50,    51,    66,     0,     0,    99,    99,    99,
       0,     0,   108,     0,    73,     0,     0,     0,     0,    78,
      79,    80,    81,    77,    76,     0,     0,     0,     0,     0,
       0,     0,    12,    22,     0,     0,    20,     0,     0,     0,
       0,     0,     0,    59,     0,     0,     0,     0,     0,     0,
      53,    54,    48,    67,     4,    99,    99,    95,    97,    98,
       0,     0,     0,   116,   112,   113,    74,    75,    14,    82,
      83,    70,    85,    86,    87,    11,     0,    15,    16,     0,
      19,     0,     0,     0,     0,     0,     0,     0,     0,   116,
       0,    49,     0,    30,     0,    94,    96,    93,   111,   110,
     115,     0,   106,     0,    27,    24,    27,     0,     0,     0,
       0,    68,     0,    58,     0,    61,     0,    64,    69,    50,
       0,   109,     0,   116,    23,    27,     0,    27,     0,     0,
      36,     0,     0,    39,     0,     0,     0,   116,    31,     0,
     114,     0,     0,     0,    28,     0,    21,    50,     0,     0,
      50,     0,    60,    63,     0,     0,    33,   107,     0,     0,
      25,    37,     0,     0,    40,    62,     0,    32,    50,     0,
      17,     0,     0,     0,     0,    65,    34,     0,     0,    38,
       0,     0,    41,     0,    27,    18,     0,     0,    35,    29,
       0,     0,     0,     0,     0,     0,     0,     0,    42,     0,
      50,    45,    43,    50,     0,    46,    44,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -162,  -162,  -162,  -162,  -162,   289,    -1,     8,  -162,  -162,
    -162,   281,  -161,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
    -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,  -162,
     -60,  -158,  -162,  -162,  -162,   -25,   -22,  -162,  -162,   163,
     165,  -162,  -162,  -162,  -162,   -56,  -162,  -162,  -162,  -127
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
       0,     1,     2,    28,     8,     9,    57,    68,   164,   238,
     141,    47,   186,   110,   179,   215,   111,   228,   243,    58,
     207,   231,    59,   210,   234,    60,   260,   264,   263,   267,
      61,    62,    63,   149,   197,    64,   160,    39,    87,    40,
      41,    42,    65,    12,    29,    70,    43,   183,   123,   161
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      38,    10,   112,    45,    69,   189,   187,    10,   187,     3,
      11,   117,   118,   119,    74,    75,    11,     5,     6,    27,
      76,    77,   174,   108,   202,     7,   204,   187,    67,   187,
     109,    14,    94,   106,    49,    95,    50,    51,    52,    76,
      77,    19,    69,    69,    69,   125,   121,    20,    53,    54,
     101,   122,   102,   103,   126,   127,   201,    56,   104,   155,
     156,    13,    76,    77,   167,   115,    67,    67,    67,    14,
     214,    17,   185,    96,   116,   142,    95,   145,   146,     4,
     148,    76,    77,   249,    15,   152,   187,   170,     5,     6,
      69,    69,    76,    77,    76,    77,     7,    76,    77,    76,
      77,    76,    77,    76,    77,    71,   171,    16,    72,    44,
      76,    77,    46,    73,    67,    67,    78,   178,   181,   198,
      91,   182,   199,    92,   256,    49,   259,    50,    51,    52,
     151,    30,   180,    93,    31,    32,    33,    34,    35,    53,
      54,    55,    97,    76,    77,   137,   191,   221,    56,   114,
     224,   138,    30,    37,   196,    31,    32,    33,    34,    35,
     200,   105,    36,   173,    76,    77,    23,    24,   236,    25,
     209,    98,   211,    79,    37,    80,    81,    82,    99,    76,
      77,   219,    76,    77,   208,   100,   222,    76,    77,    76,
      77,    83,    84,    85,    86,   107,   229,    76,    77,   213,
     262,   233,   223,   265,    76,    77,     4,   225,    52,   230,
      66,    76,    77,    21,    22,     5,     6,   232,     5,     6,
      88,    89,    90,     7,   237,   175,     7,    56,   176,   177,
     254,   241,   113,   257,    23,    24,   120,    25,    26,   124,
     195,   128,   217,   182,   226,   182,   135,   182,   129,   130,
     131,    76,    77,   132,   133,   134,   143,   144,    85,    86,
     136,   139,   140,   147,   150,   154,   153,   157,   158,   162,
     159,    76,   163,   168,   165,   166,   169,   172,   190,   184,
     188,   203,   205,   192,   218,   240,   194,   193,   212,   220,
     235,   206,   216,   247,   250,   253,   227,    18,     0,     0,
     239,   252,   255,   242,   246,   244,   245,   251,    48,   248,
       0,   258,     0,     0,   261,     0,   266,   268
};

static const yytype_int16 yycheck[] =
{
      22,     2,    62,    25,    29,   166,   164,     8,   166,     0,
       2,    67,    68,    69,    36,    37,     8,    20,    21,    42,
      18,    19,   149,     7,   185,    28,   187,   185,    29,   187,
      14,    20,    43,    55,     6,    46,     8,     9,    10,    18,
      19,    38,    67,    68,    69,    43,    20,    44,    20,    21,
      39,    25,    41,    42,    76,    77,   183,    29,    47,   115,
     116,    20,    18,    19,    43,    66,    67,    68,    69,    20,
     197,     3,    44,    43,    66,    97,    46,    99,   100,    11,
     102,    18,    19,   244,    20,   107,   244,    43,    20,    21,
     115,   116,    18,    19,    18,    19,    28,    18,    19,    18,
      19,    18,    19,    18,    19,    39,    43,    20,    42,    25,
      18,    19,    21,    47,   115,   116,    40,    43,    43,   179,
      40,    46,    43,    38,    43,     6,    43,     8,     9,    10,
      38,    20,   154,    20,    23,    24,    25,    26,    27,    20,
      21,    22,    42,    18,    19,    38,   168,   207,    29,     4,
     210,    44,    20,    42,   176,    23,    24,    25,    26,    27,
     182,    20,    30,    38,    18,    19,    38,    39,   228,    41,
     192,    42,   194,    13,    42,    15,    16,    17,    42,    18,
      19,   203,    18,    19,    38,    42,   208,    18,    19,    18,
      19,    31,    32,    33,    34,    42,   218,    18,    19,    38,
     260,   223,    38,   263,    18,    19,    11,    38,    10,    38,
      12,    18,    19,    38,    39,    20,    21,    38,    20,    21,
      35,    36,    37,    28,    38,    38,    28,    29,    41,    42,
     252,    38,    38,   255,    38,    39,    45,    41,    42,    20,
      43,    38,    43,    46,    43,    46,    38,    46,    85,    86,
      87,    18,    19,    88,    89,    90,    20,    21,    33,    34,
      39,    21,    38,    25,    20,    42,    44,    38,    40,    42,
      40,    18,    25,    41,    20,    44,    20,    40,    44,    40,
      39,    22,    25,    41,    22,    20,    41,    44,    38,    40,
      38,    45,    44,    20,    20,    20,    45,     8,    -1,    -1,
      45,    33,    33,    45,    41,    45,    45,    41,    27,    45,
      -1,    44,    -1,    -1,    44,    -1,    45,    45
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    49,    50,     0,    11,    20,    21,    28,    52,    53,
      54,    55,    91,    20,    20,    20,    20,     3,    53,    38,
      44,    38,    39,    38,    39,    41,    42,    42,    51,    92,
      20,    23,    24,    25,    26,    27,    30,    42,    84,    85,
      87,    88,    89,    94,    25,    84,    21,    59,    59,     6,
       8,     9,    10,    20,    21,    22,    29,    54,    67,    70,
      73,    78,    79,    80,    83,    90,    12,    54,    55,    83,
      93,    39,    42,    47,    84,    84,    18,    19,    40,    13,
      15,    16,    17,    31,    32,    33,    34,    86,    35,    36,
      37,    40,    38,    20,    43,    46,    43,    42,    42,    42,
      42,    39,    41,    42,    47,    20,    84,    42,     7,    14,
      61,    64,    78,    38,     4,    54,    55,    93,    93,    93,
      45,    20,    25,    96,    20,    43,    84,    84,    38,    87,
      87,    87,    88,    88,    88,    38,    39,    38,    44,    21,
      38,    58,    84,    20,    21,    84,    84,    25,    84,    81,
      20,    38,    84,    44,    42,    93,    93,    38,    40,    40,
      84,    97,    42,    25,    56,    20,    44,    43,    41,    20,
      43,    43,    40,    38,    97,    38,    41,    42,    43,    62,
      84,    43,    46,    95,    40,    44,    60,    79,    39,    60,
      44,    84,    41,    44,    41,    43,    84,    82,    78,    43,
      84,    97,    60,    22,    60,    25,    45,    68,    38,    84,
      71,    84,    38,    38,    97,    63,    44,    43,    22,    84,
      40,    78,    84,    38,    78,    38,    43,    45,    65,    84,
      38,    69,    38,    84,    72,    38,    78,    38,    57,    45,
      20,    38,    45,    66,    45,    45,    41,    20,    45,    60,
      20,    41,    33,    20,    84,    33,    43,    84,    44,    43,
      74,    44,    78,    76,    75,    78,    45,    77,    45
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    50,    51,    49,    52,    52,    53,    53,    53,
      54,    54,    54,    54,    54,    55,    56,    57,    55,    55,
      58,    55,    59,    59,    59,    59,    59,    60,    60,    60,
      62,    63,    61,    65,    66,    64,    68,    69,    67,    71,
      72,    70,    74,    75,    73,    76,    77,    73,    78,    78,
      78,    79,    79,    79,    79,    79,    79,    79,    80,    81,
      80,    80,    80,    80,    82,    80,    80,    80,    83,    83,
      84,    84,    84,    84,    85,    85,    86,    86,    86,    86,
      86,    86,    87,    87,    87,    88,    88,    88,    88,    89,
      90,    91,    92,    91,    93,    93,    93,    93,    93,    93,
      94,    94,    94,    94,    94,    94,    95,    94,    96,    94,
      94,    94,    94,    94,    97,    97,    97
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     0,     0,     6,     1,     2,     1,     1,     1,
       3,     6,     5,     3,     6,     6,     0,     0,    13,     6,
       0,     9,     2,     5,     4,     7,     0,     0,     2,     7,
       0,     0,     6,     0,     0,     9,     0,     0,     9,     0,
       0,     9,     0,     0,    19,     0,     0,    20,     2,     3,
       0,     1,     1,     2,     2,     1,     1,     1,     4,     0,
       6,     4,     7,     6,     0,     8,     1,     2,     4,     4,
       3,     1,     1,     2,     3,     3,     1,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     1,
       1,     3,     0,     7,     3,     2,     3,     2,     2,     0,
       1,     1,     1,     1,     1,     1,     0,     7,     0,     5,
       4,     4,     3,     3,     3,     1,     0
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
  case 2: /* $@1: %empty  */
#line 65 "limbaj.y"
    {
        global=new SymTable("Program","GLOBAL:");
        current=global;
    }
#line 1368 "limbaj.tab.c"
    break;

  case 3: /* $@2: %empty  */
#line 70 "limbaj.y"
    {
        SymTable *nou=new SymTable("Main_Program","MAIN:",current);

        current->addScope(nou);
        current=nou;


    }
#line 1381 "limbaj.tab.c"
    break;

  case 4: /* program: $@1 global_list BGIN $@2 main END  */
#line 79 "limbaj.y"
    {
        current=current->parinte;
        cout<<current->nume<<"-ul s-a incheiat cu "<<errorCount<<" erori\n";
    }
#line 1390 "limbaj.tab.c"
    break;

  case 10: /* declarare_variabile: TIP NUME ';'  */
#line 101 "limbaj.y"
        { current->addVariabila((yyvsp[-2].val_str),(yyvsp[-1].val_str)); }
#line 1396 "limbaj.tab.c"
    break;

  case 11: /* declarare_variabile: TIP NUME '[' INTEGER ']' ';'  */
#line 104 "limbaj.y"
        {current->addVariabila((yyvsp[-5].val_str),(yyvsp[-4].val_str),stoi((yyvsp[-2].val_str)));}
#line 1402 "limbaj.tab.c"
    break;

  case 12: /* declarare_variabile: TIP NUME '=' conditie ';'  */
#line 107 "limbaj.y"
    {

        if(strcmp((yyvsp[-4].val_str),(yyvsp[-1].pair).tip)!=0)
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-4].val_str) <<"\" si " << (yyvsp[-1].pair).tip <<" nu au acelasi tip(1)\n",errorCount++;
        else
        {
            current->addVariabila((yyvsp[-4].val_str),(yyvsp[-3].val_str),0,(yyvsp[-1].pair).rad->compute().value.c_str());
        }
    }
#line 1416 "limbaj.tab.c"
    break;

  case 13: /* declarare_variabile: NUME NUME ';'  */
#line 118 "limbaj.y"
    {
        if(global->existsScope((yyvsp[-2].val_str))==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].val_str) <<"\" tip necunoscut(2)\n",errorCount++;
        }
        else  if(current->isDefined((yyvsp[-2].val_str))==true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].val_str) <<"\" este deja definit(3)\n",errorCount++;
        }
        else
            current->addVariabila((yyvsp[-2].val_str),(yyvsp[-1].val_str));
    }
#line 1433 "limbaj.tab.c"
    break;

  case 14: /* declarare_variabile: NUME NUME '[' conditie ']' ';'  */
#line 132 "limbaj.y"
    {
        if(global->existsScope((yyvsp[-5].val_str))==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str) <<"\" tip necunoscut(2)\n",errorCount++;
        }
        else  if(current->isDefined((yyvsp[-5].val_str))==true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str) <<"\" este deja definit(3)\n",errorCount++;
        }
        else
            current->addVariabila((yyvsp[-5].val_str),(yyvsp[-4].val_str),stoi((yyvsp[-2].pair).val));

    }
#line 1451 "limbaj.tab.c"
    break;

  case 15: /* declarare_functii: TIP NUME '(' list_param ')' ';'  */
#line 151 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-4].val_str),"FUNCTIE:",current,(yyvsp[-5].val_str));
        current->addScope(nou,param);
        param.clear();
    }
#line 1461 "limbaj.tab.c"
    break;

  case 16: /* $@3: %empty  */
#line 160 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-4].val_str),"FUNCTIE:",current,(yyvsp[-5].val_str));
        current->addScope(nou,param);
        current=nou;
        param.clear();
    }
#line 1472 "limbaj.tab.c"
    break;

  case 17: /* $@4: %empty  */
#line 171 "limbaj.y"
    {
        string aux=current->returnType;

        char *aux1=(yyvsp[-1].pair).tip;

        strcpy(aux1,aux.c_str());

        if(strcmp(aux1,(yyvsp[-1].pair).tip)!=0)
            {cout<<"Warning la linia "<<yylineno<< ": functia si "<< (yyvsp[-1].pair).val <<" nu au acelasi tip(4)\n";errorCount++;}

    }
#line 1488 "limbaj.tab.c"
    break;

  case 18: /* declarare_functii: TIP NUME '(' list_param ')' '{' $@3 corp_func RETURN conditie ';' $@4 '}'  */
#line 183 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1496 "limbaj.tab.c"
    break;

  case 19: /* declarare_functii: VOID NUME '(' list_param ')' ';'  */
#line 187 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-4].val_str),"FUNCTIE:",current,(yyvsp[-5].val_str));
        current->addScope(nou,param);
        param.clear();
    }
#line 1506 "limbaj.tab.c"
    break;

  case 20: /* $@5: %empty  */
#line 194 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-3].val_str),"FUNCTIE:",current,(yyvsp[-4].val_str));
        current->addScope(nou,param);
        current=nou;
        param.clear();
    }
#line 1517 "limbaj.tab.c"
    break;

  case 21: /* declarare_functii: VOID NUME '(' list_param ')' $@5 '{' corp_func '}'  */
#line 201 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1525 "limbaj.tab.c"
    break;

  case 22: /* list_param: TIP NUME  */
#line 211 "limbaj.y"
    {param.push_back({"parametru var: ",(yyvsp[-1].val_str),(yyvsp[0].val_str)});}
#line 1531 "limbaj.tab.c"
    break;

  case 23: /* list_param: TIP NUME '[' INTEGER ']'  */
#line 214 "limbaj.y"
    {param.push_back({"parametru array: ",(yyvsp[-4].val_str),(yyvsp[-3].val_str),stoi((yyvsp[-1].val_str))});}
#line 1537 "limbaj.tab.c"
    break;

  case 24: /* list_param: list_param ',' TIP NUME  */
#line 217 "limbaj.y"
    {param.push_back({"parametru var: ",(yyvsp[-1].val_str),(yyvsp[0].val_str)});}
#line 1543 "limbaj.tab.c"
    break;

  case 25: /* list_param: list_param ',' TIP NUME '[' INTEGER ']'  */
#line 220 "limbaj.y"
    {param.push_back({"parametru array: ",(yyvsp[-4].val_str),(yyvsp[-3].val_str),stoi((yyvsp[-1].val_str))});}
#line 1549 "limbaj.tab.c"
    break;

  case 30: /* $@6: %empty  */
#line 237 "limbaj.y"
    {
        SymTable *nou=new SymTable("","ELSE:",current);
        current->addScope(nou);
        current=nou;
    }
#line 1559 "limbaj.tab.c"
    break;

  case 31: /* $@7: %empty  */
#line 245 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1567 "limbaj.tab.c"
    break;

  case 33: /* $@8: %empty  */
#line 256 "limbaj.y"
    {
        SymTable *nou=new SymTable("","ELIF:",current);
        current->addScope(nou);
        current=nou;
    }
#line 1577 "limbaj.tab.c"
    break;

  case 34: /* $@9: %empty  */
#line 262 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1585 "limbaj.tab.c"
    break;

  case 36: /* $@10: %empty  */
#line 271 "limbaj.y"
    {
        SymTable *nou=new SymTable("","IF:",current);
        current->addScope(nou);
        current=nou;
    }
#line 1595 "limbaj.tab.c"
    break;

  case 37: /* $@11: %empty  */
#line 277 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1603 "limbaj.tab.c"
    break;

  case 39: /* $@12: %empty  */
#line 287 "limbaj.y"
    {
        SymTable *nou=new SymTable("","WHILE:",current);
        current->addScope(nou);
        current=nou;
    }
#line 1613 "limbaj.tab.c"
    break;

  case 40: /* $@13: %empty  */
#line 293 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1621 "limbaj.tab.c"
    break;

  case 42: /* $@14: %empty  */
#line 303 "limbaj.y"
    {
        SymTable *nou=new SymTable("","FOR:",current);

        variabile *aux1=current->returnVariabile((yyvsp[-12].val_str)),*aux2=current->returnVariabile((yyvsp[-6].val_str)),*aux3=current->returnVariabile((yyvsp[-4].val_str));
        if(aux1==nullptr||aux2==nullptr||aux3==nullptr)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  "o variabila nu este definita(5)\n";
            errorCount++;
        }
        else if(strcmp(aux1->tip.c_str(),(yyvsp[-10].pair).tip)!=0||strcmp(aux2->tip.c_str(),aux3->tip.c_str())!=0||strcmp(aux2->tip.c_str(),(yyvsp[-2].pair).tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  "tipuri incompatibile(6)\n";
            errorCount++;
        }
        else
        {
            current->addScope(nou);

        }

        current=nou;
    }
#line 1648 "limbaj.tab.c"
    break;

  case 43: /* $@15: %empty  */
#line 327 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1656 "limbaj.tab.c"
    break;

  case 45: /* $@16: %empty  */
#line 333 "limbaj.y"
    {
        SymTable *nou=new SymTable("","FOR:",current);
        variabile *aux1=current->returnVariabile((yyvsp[-6].val_str)),*aux2=current->returnVariabile((yyvsp[-4].val_str));
        if(aux1==nullptr||aux2==nullptr||current->isDefined((yyvsp[-12].val_str))==false)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  " o variabila nu este definita(7)\n";
            errorCount++;
        }
        else if(strcmp((yyvsp[-13].val_str),(yyvsp[-10].pair).tip)!=0||strcmp(aux1->tip.c_str(),aux2->tip.c_str())!=0||strcmp(aux2->tip.c_str(),(yyvsp[-2].pair).tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ""<<  " tipuri incompatibile(8)\n";
            errorCount++;
        }
        else
        {
            current->addScope(nou);
        }

        current=nou;
    }
#line 1681 "limbaj.tab.c"
    break;

  case 46: /* $@17: %empty  */
#line 355 "limbaj.y"
    {
        current=current->parinte;
    }
#line 1689 "limbaj.tab.c"
    break;

  case 58: /* apeluri: NUME '=' conditie ';'  */
#line 392 "limbaj.y"
    {
        variabile *aux=current->returnVariabile((yyvsp[-3].val_str));

        if(current->isDefined((yyvsp[-3].val_str))!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-3].val_str)<<"\" nu este definit(9)\n";
            errorCount++;
        }
        else if(aux==nullptr||strcmp(aux->tip.c_str(),(yyvsp[-1].pair).tip)!=0)
        {
            cout<<"Warning la linia "<<yylineno<< ": " <<" tipuri incompatibile(10)\n";
            errorCount++;
        }
        else
        {
            SymTable *ar=current->getScope((yyvsp[-3].val_str));
            if(current->tip_scop=="MAIN:")
            ar->modificareVariabila((yyvsp[-3].val_str),(yyvsp[-1].pair).rad->compute().value.c_str());
        }

    }
#line 1715 "limbaj.tab.c"
    break;

  case 59: /* $@18: %empty  */
#line 415 "limbaj.y"
               { param_value.clear();}
#line 1721 "limbaj.tab.c"
    break;

  case 60: /* apeluri: NUME '(' $@18 param_val ')' ';'  */
#line 416 "limbaj.y"
    {

        SymTable *aux=nullptr,*aux12;
        aux=global->verScopeColegi((yyvsp[-5].val_str));

        for(int i=0; i<global->tabla.size(); i++)
        {
            aux12=global->tabla[i].second->verScopeColegi((yyvsp[-5].val_str));
            if(aux12!=nullptr&&aux12->nume==(yyvsp[-5].val_str))
            {

                aux=global->tabla[i].second->verScopeColegi((yyvsp[-5].val_str));
                break;

            }

        }

        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str)<<"\" nu este definita(11)\n",errorCount++;

        else if(param_value.size()!=aux->param.size()&&aux->tip_scop!="CLASA:")
        {

            cout<<"Warning la linia "<<yylineno<< ": "<< "numar de argumente invalide(12)\n";errorCount++;
        }
        else if(aux->tip_scop=="CLASA:")
        {
            aux=aux->verScopeColegi((yyvsp[-5].val_str));

            if(aux!=nullptr &&aux->nume!=(yyvsp[-5].val_str))
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str)<<"\" nu este definita(13)\n";errorCount++;
            }
            else
            {
                bool gasit=true;
                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    }
                if(gasit==false)
                    cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(14)\n",errorCount++;
            }

        }
        else
        {
            bool gasit=true;
            for(int i=0; i<param_value.size(); i++)

                if(param_value[i].tip!=aux->param[i].tip)
                {
                    gasit=false;

                    break;
                }


            if(gasit==false)
                cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(15)\n",errorCount++;
        }

    }
#line 1792 "limbaj.tab.c"
    break;

  case 61: /* apeluri: NUME '.' NUME ';'  */
#line 483 "limbaj.y"
    {
        SymTable *aux=current->getScope((yyvsp[-3].val_str));
        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-3].val_str)<<"\" clasa nu este definita(14)\n",errorCount++;
        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType((yyvsp[-3].val_str));
            char* charPtr = &tip[0];
            aux2=global->verScopeColegi(charPtr);
            if(aux2->existsVariabila((yyvsp[-1].val_str))==false)
                cout<<" Warning la linia "<<yylineno<< ": \""<< (yyvsp[-1].val_str)<<"\" nu este definit(15)\n",errorCount++;
        }

    }
#line 1812 "limbaj.tab.c"
    break;

  case 62: /* apeluri: NUME '[' INTEGER ']' '=' conditie ';'  */
#line 500 "limbaj.y"
    {
        if(current->isDefined((yyvsp[-6].val_str))==false)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << (yyvsp[-6].val_str)<<"\" nu este definit(16)\n";errorCount++;
        }
        else
        {

            variabile *aux=current->returnVariabile((yyvsp[-6].val_str));

            if(current->isDefined((yyvsp[-6].val_str))!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-6].val_str)<<"\" nu este definit(17)\n";errorCount++;
            }
            else if(aux==nullptr||strcmp(aux->tip.c_str(),(yyvsp[-1].pair).tip)!=0)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" tipuri incompatibile(18)\n";errorCount++;
            }
            else
            {
                SymTable *ar=current->getScope((yyvsp[-6].val_str));
                ar->modificareVector((yyvsp[-6].val_str),(yyvsp[-1].pair).rad->compute().value.c_str(),stoi((yyvsp[-4].val_str)));
            }


        }
    }
#line 1844 "limbaj.tab.c"
    break;

  case 63: /* apeluri: NUME '.' NUME '=' conditie ';'  */
#line 528 "limbaj.y"
    {
        SymTable *aux=current->getScope((yyvsp[-5].val_str));
        if(aux==nullptr)
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str)<<"\" clasa nu este definita(19)\n",errorCount++;
        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType((yyvsp[-5].val_str));
            char* charPtr = &tip[0];
            aux2=global->verScopeColegi(charPtr);

            if(aux2->existsVariabila((yyvsp[-3].val_str))==false)
                cout<<" Warning la linia "<<yylineno<< ": \""<< (yyvsp[-3].val_str)<<"\" nu este definit(20)\n",errorCount++;

            else
            {

            }

        }

    }
#line 1871 "limbaj.tab.c"
    break;

  case 64: /* $@19: %empty  */
#line 552 "limbaj.y"
                        { param_value.clear();}
#line 1877 "limbaj.tab.c"
    break;

  case 65: /* apeluri: NUME '.' NUME '(' $@19 param_val ')' ';'  */
#line 553 "limbaj.y"
    {
        SymTable *aux=nullptr,*aux12;
        aux=current->getScope((yyvsp[-7].val_str));
        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-7].val_str)<<"\" clasa nu este definita(33)\n";
            errorCount++;
        }

        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType((yyvsp[-7].val_str));
            char* charPtr = &tip[0];
            char *tiip=new char[2000];
            strcpy(tiip,tip.c_str());
            aux=global->verScopeColegi(tiip);

            if(aux!=nullptr)
                aux=aux->verScopeColegi((yyvsp[-5].val_str));

            if(aux==nullptr)
            {	cout<<" Warning la linia "<<yylineno<< ": \""<< (yyvsp[-5].val_str)<<"\" nu este definit(34)\n";
                errorCount++;
            }
            else
            {
                bool gasit=true;

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    }

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(35)\n";errorCount++;

                }
            }

        }

    }
#line 1926 "limbaj.tab.c"
    break;

  case 68: /* functii_predefinite: PRINT '(' conditie ')'  */
#line 606 "limbaj.y"
    {
        if(current->tip_scop=="MAIN:")
        cout<<"Info linia "<<yylineno<< "-> Rezultat: PRINT("<<(yyvsp[-1].pair).val<<")="<<(yyvsp[-1].pair).rad->compute().value.c_str()<<'\n';
    }
#line 1935 "limbaj.tab.c"
    break;

  case 69: /* functii_predefinite: TYPEOF '(' conditie ')'  */
#line 612 "limbaj.y"
    {
        if(current->tip_scop=="MAIN:")
        cout<<"Info linia "<<yylineno<< "-> Rezultat: TYPEOF("<<(yyvsp[-1].pair).val<<")="<<(yyvsp[-1].pair).rad->arbType()<<'\n';
    }
#line 1944 "limbaj.tab.c"
    break;

  case 70: /* conditie: expr comparatie expr  */
#line 620 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,(yyvsp[-1].val_str));
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;

                    strcpy((yyval.pair).tip,"bool");
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr comp"), strdup(""), strdup((yyvsp[-1].val_str)), st, dr);
                    (yyval.pair).rad=root;
                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(24)\n";errorCount++;

                }


            }
        }
    }
#line 1977 "limbaj.tab.c"
    break;

  case 71: /* conditie: expr  */
#line 650 "limbaj.y"
    {
        (yyval.pair).tip=(yyvsp[0].pair).tip;
        (yyval.pair).val=(yyvsp[0].pair).val;
        (yyval.pair).rad=(yyvsp[0].pair).rad;
    }
#line 1987 "limbaj.tab.c"
    break;

  case 72: /* conditie: conditie_logica  */
#line 656 "limbaj.y"
    {
        (yyval.pair).tip=strdup("bool");
        (yyval.pair).val=(yyvsp[0].pair).val;
        (yyval.pair).rad=(yyvsp[0].pair).rad;

    }
#line 1998 "limbaj.tab.c"
    break;

  case 73: /* conditie: '!' conditie  */
#line 663 "limbaj.y"
    {
        (yyval.pair).tip=(yyvsp[0].pair).tip;
        char*a2=(yyvsp[-1].val_str);
        strcat(a2,(yyvsp[0].pair).val);
        strcpy((yyval.pair).val,a2);
        AST *st = (yyvsp[0].pair).rad;
        AST *root = new AST(strdup(""), strdup("string"), strdup("&&"), st);
        (yyval.pair).rad=root;
    }
#line 2012 "limbaj.tab.c"
    break;

  case 74: /* conditie_logica: conditie AND conditie  */
#line 676 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0&& strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"&&");
                    strcat(aux,aux1);
                    char* aux3=(yyvsp[-2].pair).tip;
                    strcpy((yyval.pair).tip,"bool");
                    strcpy((yyval.pair).val,aux);

                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr bool"), strdup("string"), strdup("&&"), st, dr);
                    (yyval.pair).rad=root;
                }
                else
                {

                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(25)\n";errorCount++;

                }


            }
        }
    }
#line 2045 "limbaj.tab.c"
    break;

  case 75: /* conditie_logica: conditie OR conditie  */
#line 705 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0 && strcmp((yyvsp[-2].pair).tip,"bool")==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"||");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,"bool");
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr bool"), strdup("string"), strdup("||"), st, dr);
                    (yyval.pair).rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(26)\n";errorCount++;

                }


            }
        }
    }
#line 2080 "limbaj.tab.c"
    break;

  case 76: /* comparatie: '>'  */
#line 739 "limbaj.y"
    {
        (yyval.val_str)=strdup(">");
    }
#line 2088 "limbaj.tab.c"
    break;

  case 77: /* comparatie: '<'  */
#line 743 "limbaj.y"
    {
        (yyval.val_str)=strdup("<");
    }
#line 2096 "limbaj.tab.c"
    break;

  case 78: /* comparatie: EQUAL  */
#line 747 "limbaj.y"
    {
        (yyval.val_str)=strdup("==");
    }
#line 2104 "limbaj.tab.c"
    break;

  case 79: /* comparatie: NEQ  */
#line 751 "limbaj.y"
    {
        (yyval.val_str)=strdup("!=");
    }
#line 2112 "limbaj.tab.c"
    break;

  case 80: /* comparatie: LEQ  */
#line 755 "limbaj.y"
    {
        (yyval.val_str)=strdup("<=");
    }
#line 2120 "limbaj.tab.c"
    break;

  case 81: /* comparatie: GEQ  */
#line 759 "limbaj.y"
    {
        (yyval.val_str)=strdup(">=");
    }
#line 2128 "limbaj.tab.c"
    break;

  case 82: /* expr: expr '+' expr  */
#line 766 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"+");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,aux3);
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("+"), st, dr);
                    (yyval.pair).rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(27)\n";errorCount++;

                }


            }
        }
    }
#line 2163 "limbaj.tab.c"
    break;

  case 83: /* expr: expr '-' expr  */
#line 798 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"-");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,(yyvsp[-2].pair).tip);
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("-"), st, dr);
                    (yyval.pair).rad=root;


                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(28)\n";errorCount++;

                }


            }
        }
    }
#line 2199 "limbaj.tab.c"
    break;

  case 84: /* expr: term  */
#line 830 "limbaj.y"
    {
        (yyval.pair).tip=(yyvsp[0].pair).tip;
        (yyval.pair).val=(yyvsp[0].pair).val;
    }
#line 2208 "limbaj.tab.c"
    break;

  case 85: /* term: term '*' term  */
#line 839 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"*");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,aux3);
                    strcpy((yyval.pair).val,aux);

                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("*"), st, dr);
                    (yyval.pair).rad=root;
                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(29)\n";errorCount++;

                }


            }
        }
    }
#line 2243 "limbaj.tab.c"
    break;

  case 86: /* term: term '/' term  */
#line 870 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"/");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,aux3);
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("/"), st, dr);
                    (yyval.pair).rad=root;

                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(30)\n";errorCount++;

                }


            }
        }
    }
#line 2278 "limbaj.tab.c"
    break;

  case 87: /* term: term '%' term  */
#line 901 "limbaj.y"
    {
        {
            {
                if(strcmp((yyvsp[-2].pair).tip,(yyvsp[0].pair).tip)==0)
                {	char* aux=(yyvsp[-2].pair).val;
                    char* aux1=(yyvsp[0].pair).val;
                    strcat(aux,"%");
                    strcat(aux,aux1);

                    char* aux3=(yyvsp[-2].pair).tip;


                    strcpy((yyval.pair).tip,aux3);
                    strcpy((yyval.pair).val,aux);
                    AST *st = (yyvsp[-2].pair).rad;
                    AST *dr = (yyvsp[0].pair).rad;
                    AST *root = new AST(strdup("expr aritm"), strdup("string"), strdup("%"), st, dr);
                    (yyval.pair).rad=root;


                }
                else
                {
                    cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].pair).val<<"\" si \" " << (yyvsp[0].pair).val <<"\" nu acelasi tip(31)\n";errorCount++;

                }


            }
        }
    }
#line 2314 "limbaj.tab.c"
    break;

  case 88: /* term: factor  */
#line 933 "limbaj.y"
    {
        (yyval.pair).tip =(yyvsp[0].pair).tip;
        (yyval.pair).val =(yyvsp[0].pair).val;
        (yyval.pair).rad=(yyvsp[0].pair).rad;
    }
#line 2324 "limbaj.tab.c"
    break;

  case 89: /* factor: valoare  */
#line 942 "limbaj.y"
    {
        (yyval.pair).tip=(yyvsp[0].pair).tip;
        (yyval.pair).val=(yyvsp[0].pair).val;
        (yyval.pair).rad=(yyvsp[0].pair).rad;
    }
#line 2334 "limbaj.tab.c"
    break;

  case 91: /* clase: CLASS NUME ';'  */
#line 957 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-1].val_str),"CLASA:",current);
        current->addScope(nou);

    }
#line 2344 "limbaj.tab.c"
    break;

  case 92: /* $@20: %empty  */
#line 966 "limbaj.y"
    {
        SymTable *nou=new SymTable((yyvsp[-1].val_str),"CLASA:",current);


        current->addScope(nou);
        current=nou;

    }
#line 2357 "limbaj.tab.c"
    break;

  case 93: /* clase: CLASS NUME '{' $@20 corp_clasa '}' ';'  */
#line 976 "limbaj.y"
    {

        current=current->parinte;
    }
#line 2366 "limbaj.tab.c"
    break;

  case 100: /* valoare: INTEGER  */
#line 992 "limbaj.y"
           {
        (yyval.pair).tip=strdup("int");
        (yyval.pair).val=strdup((yyvsp[0].val_str));
        (yyval.pair).rad=new AST(strdup("var"), strdup("int"), strdup((yyvsp[0].val_str)));
    }
#line 2376 "limbaj.tab.c"
    break;

  case 101: /* valoare: FLOAT  */
#line 997 "limbaj.y"
           {
        (yyval.pair).tip=strdup("float");
        (yyval.pair).val=strdup((yyvsp[0].val_str));
        (yyval.pair).rad=new AST(strdup("var"), strdup("float"), strdup((yyvsp[0].val_str)));
    }
#line 2386 "limbaj.tab.c"
    break;

  case 102: /* valoare: CHAR  */
#line 1002 "limbaj.y"
          {
        (yyval.pair).tip=strdup("char");
        (yyval.pair).val=strdup((yyvsp[0].val_str));
        (yyval.pair).rad=new AST(strdup("var"), strdup("char"), strdup((yyvsp[0].val_str)));
    }
#line 2396 "limbaj.tab.c"
    break;

  case 103: /* valoare: STRING  */
#line 1007 "limbaj.y"
            {  (yyval.pair).tip=strdup("string");
        (yyval.pair).val=strdup((yyvsp[0].val_str));
        (yyval.pair).rad=new AST(strdup("var"), strdup("string"), strdup((yyvsp[0].val_str)));
    }
#line 2405 "limbaj.tab.c"
    break;

  case 104: /* valoare: BOOL  */
#line 1012 "limbaj.y"
          {
        (yyval.pair).tip=strdup("bool");
        (yyval.pair).val=strdup((yyvsp[0].val_str));
        (yyval.pair).rad=new AST(strdup("var"), strdup("bool"), strdup((yyvsp[0].val_str)));
    }
#line 2415 "limbaj.tab.c"
    break;

  case 105: /* valoare: NUME  */
#line 1018 "limbaj.y"
    {
        if(current->isDefined((yyvsp[0].val_str))==true)
        {
            variabile *aux=current->returnVariabile((yyvsp[0].val_str));

            if(aux!= nullptr )
            {
                string ax=aux->tip;

                (yyval.pair).tip=strdup(&ax[0]);

                if(aux->value.size()!=0&&aux->value[0]!="")
                {	ax=aux->value[0];

                    (yyval.pair).val=strdup(&ax[0]);
                    (yyval.pair).rad=new AST(strdup("var"), (yyval.pair).tip, (yyval.pair).val);
                }
                else {
                    (yyval.pair).val=strdup("");
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, strdup(""));
                }
            }
            else
            {
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
                (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            }



        }
        else
        {
            cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[0].val_str)<<"\" nu este definit(32)\n";
            (yyval.pair).tip=strdup("");
            (yyval.pair).val=strdup("");
            (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
        }

    }
#line 2461 "limbaj.tab.c"
    break;

  case 106: /* $@21: %empty  */
#line 1059 "limbaj.y"
                        {param_value.clear();}
#line 2467 "limbaj.tab.c"
    break;

  case 107: /* valoare: NUME '.' NUME '(' $@21 param_val ')'  */
#line 1061 "limbaj.y"
    {
        SymTable *aux=nullptr,*aux12;
        aux=current->getScope((yyvsp[-6].val_str));

        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-6].val_str)<<"\" clasa nu este definita(33)\n";errorCount++;
            (yyval.pair).tip=strdup("");
             (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            (yyval.pair).val=strdup("");
        }

        else
        {
            SymTable *aux2=nullptr;
            string tip=aux->getType((yyvsp[-6].val_str));

            char* charPtr = &tip[0];

            char *tiip=new char[2000];

            strcpy(tiip,tip.c_str());

            aux=global->verScopeColegi(tiip);

            if(aux!=nullptr)
                aux=aux->verScopeColegi((yyvsp[-4].val_str));

            if(aux==nullptr)
            {	cout<<" Warning la linia "<<yylineno<< ": \""<< (yyvsp[-4].val_str)<<"\" nu este definit(34)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                 (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
                (yyval.pair).val=strdup("");
            }
            else

            {
                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,(yyvsp[-6].val_str));
                strcat(aax,".");
                strcat(aax,(yyvsp[-4].val_str));
                strcat(aax,"(");

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    } else
                    {
                        strcat(aax,param_value[i].nume.c_str());
                    }
                strcat(aax,")");

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(35)\n";errorCount++;
                    (yyval.pair).tip=strdup("");
                     (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
                    (yyval.pair).val=strdup("");
                }
                else
                {
                    (yyval.pair).val=aax;
                    strcpy(tiip,aux->returnType.c_str());


                    (yyval.pair).tip=tiip;
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, (yyval.pair).val);

                }

            }

        }

    }
#line 2548 "limbaj.tab.c"
    break;

  case 108: /* $@22: %empty  */
#line 1139 "limbaj.y"
               {param_value.clear();}
#line 2554 "limbaj.tab.c"
    break;

  case 109: /* valoare: NUME '(' $@22 param_val ')'  */
#line 1140 "limbaj.y"
    {

        SymTable *aux=nullptr,*aux12;
        aux=global->verScopeColegi((yyvsp[-4].val_str));



        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-4].val_str)<<"\" nu este definita(36)\n";errorCount++;
            (yyval.pair).tip=strdup("");
            (yyval.pair).val=strdup("");
             (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
        }

        else if(param_value.size()!=aux->param.size()&&aux->tip_scop!="CLASA:")
        {

            cout<<" Warning la linia "<<yylineno<< ": "<< "numar de argumente invalide(37)\n";errorCount++;
            (yyval.pair).tip=strdup("");
             (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            (yyval.pair).val=strdup("");
        }
        else if(aux->tip_scop=="CLASA:")
        {
            aux=aux->verScopeColegi((yyvsp[-4].val_str));

            if(aux!=nullptr &&aux->nume!=(yyvsp[-4].val_str))
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-4].val_str)<<"\" nu este definita(38)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
                 (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else
            {

                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,(yyvsp[-4].val_str));


                strcat(aax,"(");

                for(int i=0; i<param_value.size(); i++)
                    if(param_value[i].tip!=aux->param[i].tip)
                    {
                        gasit=false;
                        break;
                    } else
                    {
                        strcat(aax,param_value[i].nume.c_str());
                    }
                strcat(aax,")");

                if(gasit==false)
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;

                    (yyval.pair).tip=strdup("");
                    (yyval.pair).val=strdup("");
                     (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
                }
                else
                {

                    (yyval.pair).val=aax;

                    char *mm=strdup("");
                    strcpy(mm,aux->returnType.c_str());

                    (yyval.pair).tip=mm;

                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, (yyval.pair).val);


                }

            }


        }
        else {

            bool gasit=true;
            char *aax=new char[2000];
            strcpy(aax,(yyvsp[-4].val_str));


            strcat(aax,"(");

            for(int i=0; i<param_value.size(); i++)
                if(param_value[i].tip!=aux->param[i].tip)
                {
                    gasit=false;
                    break;
                } else
                {
                    strcat(aax,param_value[i].nume.c_str());
                }
            strcat(aax,")");

            if(gasit==false)
            {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;
 (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
            }
            else
            {

                (yyval.pair).val=aax;

                char *mm=strdup("");
                strcpy(mm,aux->returnType.c_str());

                (yyval.pair).tip=mm;

                (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, (yyval.pair).val);


            }

        }
    }
#line 2682 "limbaj.tab.c"
    break;

  case 110: /* valoare: NUME '[' INTEGER ']'  */
#line 1264 "limbaj.y"
                           {
        if(current->isDefined((yyvsp[-3].val_str))!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << (yyvsp[-3].val_str)<<"\" nu este definit(40)\n";errorCount++;
            (yyval.pair).tip=strdup("");
            (yyval.pair).val=strdup("");
        }
        else
        {

            variabile *aux=current->returnVariabile((yyvsp[-3].val_str));

            if(current->isDefined((yyvsp[-3].val_str))!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-3].val_str)<<"\" nu este definit(41)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
            }
            else if(aux==nullptr)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" indexul nu este intreg(42)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).rad=new AST(strdup("default"), strdup("int"), strdup(""));
                (yyval.pair).val=strdup("");
            }
            else
            {
                SymTable *ar=current->getScope((yyvsp[-3].val_str));
                variabile *varr=ar->returnVariabile((yyvsp[-3].val_str));

                char *axx=new char[2000];

                strcpy(axx,(yyvsp[-3].val_str));
                strcat(axx,"[");

                if(((yyvsp[-1].val_str)[0]>='a'&& (yyvsp[-1].val_str)[0]<='z')||((yyvsp[-1].val_str)[0]>='A'&& (yyvsp[-1].val_str)[0]<='Z'))
                    strcat(axx,"");
                else
                    strcat(axx,(yyvsp[-1].val_str));

                strcat(axx,"]");
                (yyval.pair).val=axx;
                char *mm=strdup("");
                strcpy(mm,varr->tip.c_str());

                (yyval.pair).tip=mm;
                char *m=new char[100];

                if(strncmp(varr->nume_scop.c_str(),"parame",5)==0)
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, strdup(""));

                else if(atoi((yyvsp[-1].val_str))<varr->size)
                {	strcpy(m,varr->value[atoi((yyvsp[-1].val_str))].c_str());
                    (yyval.pair).rad=new AST(strdup("var"), (yyval.pair).tip, m);
                }
                else
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, strdup(axx));

            }
        }

    }
#line 2749 "limbaj.tab.c"
    break;

  case 111: /* valoare: NUME '[' NUME ']'  */
#line 1327 "limbaj.y"
                        {
        if(current->isDefined((yyvsp[-3].val_str))!=true)
        {
            cout<<"Warning la linia "<<yylineno<< ": \"" << (yyvsp[-3].val_str)<<"\" nu este definit(40)\n";errorCount++;
            (yyval.pair).tip=strdup("");
            (yyval.pair).val=strdup("");
             (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));

        }
        else
        {

            variabile *aux=current->returnVariabile((yyvsp[-3].val_str));
            variabile *aux1=current->returnVariabile((yyvsp[-1].val_str));
            if(current->isDefined((yyvsp[-3].val_str))!=true)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-3].val_str)<<"\" nu este definit(41)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
            }
            else if(strcmp("int",aux1->tip.c_str())!=0)
            {
                cout<<"Warning la linia "<<yylineno<< ": " <<" indexul nu este intreg(42)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
                 (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else if(aux==nullptr)
            {
                (yyval.pair).rad=new AST(strdup("default"), strdup("int"), strdup(""));
            }
            else
            {

                SymTable *ar=current->getScope((yyvsp[-3].val_str));
                variabile *varr=ar->returnVariabile((yyvsp[-3].val_str));

                char *axx=new char[2000];

                strcpy(axx,(yyvsp[-3].val_str));
                strcat(axx,"[");

                if(((yyvsp[-1].val_str)[0]>='a'&& (yyvsp[-1].val_str)[0]<='z')||((yyvsp[-1].val_str)[0]>='A'&& (yyvsp[-1].val_str)[0]<='Z'))
                    strcat(axx,"");
                else
                    strcat(axx,(yyvsp[-1].val_str));

                strcat(axx,"]");
                (yyval.pair).val=axx;
                char *mm=strdup("");
                strcpy(mm,varr->tip.c_str());

                (yyval.pair).tip=mm;
                char *m=new char[100];

                if(aux1!=nullptr)
                {	strcpy(m,aux1->value[0].c_str());
                    (yyval.pair).rad=new AST(strdup("var"), (yyval.pair).tip, m);
                }
                else
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, strdup(axx));

            }
        }

    }
#line 2820 "limbaj.tab.c"
    break;

  case 112: /* valoare: NUME '.' NUME  */
#line 1394 "limbaj.y"
    {
        SymTable *aux=current->getScope((yyvsp[-2].val_str));
        if(aux==nullptr)
        {	cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].val_str)<<"\" clasa nu este definita(43)\n";errorCount++;
            (yyval.pair).tip=strdup("");
            (yyval.pair).val=strdup("");
             (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
        }
        else
        {

            variabile *a=aux->returnVariabile((yyvsp[-2].val_str));

            char *aa=new char[100];
            strcpy(aa,a->tip.c_str());
            aux=global->verScopeColegi(aa);

            if(aux==nullptr)
            {
                cout<<"Warning la linia "<<yylineno<< ": \""<< (yyvsp[-2].val_str)<<"\" nu este definita(38)\n";errorCount++;
                (yyval.pair).tip=strdup("");
                (yyval.pair).val=strdup("");
                 (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
            }
            else
            {
                variabile *varr=aux->returnVariabile((yyvsp[0].val_str));
                bool gasit=true;
                char *aax=new char[2000];
                strcpy(aax,(yyvsp[-2].val_str));
                strcat(aax,".");

                if(varr!=nullptr)
                {
                    strcat(aax,(yyvsp[0].val_str));
                    (yyval.pair).val=aax;

                    char *mm=strdup("");
                    strcpy(mm,varr->tip.c_str());

                    (yyval.pair).tip=mm;
                    (yyval.pair).rad=new AST(strdup("default"), (yyval.pair).tip, (yyval.pair).val);

                }


                else
                {	cout<<"Warning la linia "<<yylineno<< ": "<< "tipuri invalide(39)\n";errorCount++;

                    (yyval.pair).tip=strdup("");
                    (yyval.pair).val=strdup("");
                    (yyval.pair).rad=new AST(strdup("default"), strdup(""), strdup(""));
                }


            }


        }}
#line 2884 "limbaj.tab.c"
    break;

  case 113: /* valoare: '(' conditie ')'  */
#line 1456 "limbaj.y"
                 {

        int n=strlen((yyvsp[-1].pair).val);
        char *aux2=(yyvsp[-1].pair).val;

        char * aux=new char[1000];
        strcpy(aux,"(");
        strcat(aux,aux2);

        strcat(aux,")");

        (yyval.pair).val=aux;

        (yyval.pair).tip=(yyvsp[-1].pair).tip;
        (yyval.pair).rad=(yyvsp[-1].pair).rad;
    }
#line 2905 "limbaj.tab.c"
    break;

  case 114: /* param_val: param_val ',' conditie  */
#line 1476 "limbaj.y"
    {
        if( !((yyvsp[0].pair).tip == nullptr || (yyvsp[0].pair).val == nullptr || strcmp((yyvsp[0].pair).tip, "") == 0 || strcmp((yyvsp[0].pair).val, "") == 0))
        {
            char * aux=new char[1000];

            strcpy(aux,(yyvsp[0].pair).tip);
            char * aux1=new char[1000];

            strcpy(aux1,(yyvsp[0].pair).val);

            param_value.push_back({"2",aux,aux1});

        }
    }
#line 2924 "limbaj.tab.c"
    break;

  case 115: /* param_val: conditie  */
#line 1491 "limbaj.y"
    {
        if (!((yyvsp[0].pair).tip == nullptr || (yyvsp[0].pair).val == nullptr || strcmp((yyvsp[0].pair).tip, "") == 0 || strcmp((yyvsp[0].pair).val, "") == 0))
        {

            char * aux=new char[44];

            strcpy(aux,(yyvsp[0].pair).tip);

            char * aux1=new char[44];
            strcpy(aux1,(yyvsp[0].pair).val);

            param_value.push_back({"2",aux,aux1});


        }
    }
#line 2945 "limbaj.tab.c"
    break;


#line 2949 "limbaj.tab.c"

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

#line 1512 "limbaj.y"


    int main(int argc, char** argv) {
        ofstream outFile("symTable_out.txt");
        if (!outFile) {
            cerr << "Eroare la deschiderea fisierului!\n";
            return 1;
        }
        yyin = fopen(argv[1], "r");
        int cnt = 0;

        yyparse();

        fclose(yyin);

        current->print(outFile);

        outFile.close();

        return 0;
    }
