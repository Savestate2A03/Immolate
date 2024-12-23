#ifndef IMMOLATE_H
#define IMMOLATE_H

#include <stdbool.h>
#include <math.h>

// Based on C++ program by 00001H and MathIsFun_
#ifndef GAME_VERSION
    #define VER1 1
    #define VER2 0
    #define VER3 1
    #define VER4 6 //1.0.1f
    #define GAME_VERSION
#endif

#define llong long long
#define ulong unsigned long long
#define uint unsigned int

typedef struct Char8 {
    char data[8];
} char8;

typedef struct Char16 {
    char data[16];
} char16;

typedef struct Ulong8 {
    ulong data[8];
} ulong8;

// Pseudohash
typedef struct Text {
    char str[256];
    int len;
} text;

// Contains every kind of thing you could search for!

typedef enum Item {
    RETRY,

    //Jokers
    J_BEGIN,

    J_C_BEGIN,
    Joker,
    Greedy_Joker,
    Lusty_Joker,
    Wrathful_Joker,
    Gluttonous_Joker,
    Jolly_Joker,
    Zany_Joker,
    Mad_Joker,
    Crazy_Joker,
    Droll_Joker,
    Sly_Joker,
    Wily_Joker,
    Clever_Joker,
    Devious_Joker,
    Crafty_Joker,
    Half_Joker,
    Credit_Card,
    Banner,
    Mystic_Summit,
    _8_Ball,
    Misprint,
    Raised_Fist,
    Chaos_the_Clown,
    Scary_Face,
    Abstract_Joker,
    Delayed_Gratification,
    Gros_Michel,
    Even_Steven,
    Odd_Todd,
    Scholar,
    Business_Card,
    Supernova,
    Ride_the_Bus,
    Egg,
    Runner,
    Ice_Cream,
    Splash,
    Blue_Joker,
    Faceless_Joker,
    Green_Joker,
    Superposition,
    To_Do_List,
    Cavendish,
    Red_Card,
    Square_Joker,
    Riff_raff,
    Photograph,
    Reserved_Parking,
    Mail_In_Rebate,
    Hallucination,
    Fortune_Teller,
    Juggler,
    Drunkard,
    Golden_Joker,
    Popcorn,
    Walkie_Talkie,
    Smiley_Face,
    Golden_Ticket,
    Swashbuckler,
    Hanging_Chad,
    Shoot_the_Moon,
    J_C_END,

    J_U_BEGIN,
    Joker_Stencil,
    Four_Fingers,
    Mime,
    Ceremonial_Dagger,
    Marble_Joker,
    Loyalty_Card,
    Dusk,
    Fibonacci,
    Steel_Joker,
    Hack,
    Pareidolia,
    Space_Joker,
    Burglar,
    Blackboard,
    Sixth_Sense,
    Constellation,
    Hiker,
    Card_Sharp,
    Madness,
    Seance,
    Shortcut,
    Hologram,
    Cloud_9,
    Rocket,
    Midas_Mask,
    Luchador,
    Gift_Card,
    Turtle_Bean,
    Erosion,
    To_the_Moon,
    Stone_Joker,
    Lucky_Cat,
    Bull,
    Diet_Cola,
    Trading_Card,
    Flash_Card,
    Spare_Trousers,
    Ramen,
    Seltzer,
    Castle,
    Mr_Bones,
    Acrobat,
    Sock_and_Buskin,
    Troubadour,
    Certificate,
    Smeared_Joker,
    Throwback,
    Rough_Gem,
    Bloodstone,
    Arrowhead,
    Onyx_Agate,
    Glass_Joker,
    Showman,
    Flower_Pot,
    Merry_Andy,
    Oops_All_6s,
    The_Idol,
    Seeing_Double,
    Matador,
    Stuntman,
    Satellite,
    Cartomancer,
    Astronomer,
    Bootstraps,
    J_U_END,

    J_R_BEGIN,
    DNA,
    Vampire,
    Vagabond,
    Baron,
    Obelisk,
    Baseball_Card,
    Ancient_Joker,
    Campfire,
    Blueprint,
    Wee_Joker,
    Hit_the_Road,
    The_Duo,
    The_Trio,
    The_Family,
    The_Order,
    The_Tribe,
    Invisible_Joker,
    Brainstorm,
    Drivers_License,
    Burnt_Joker,
    J_R_END,

    J_L_BEGIN,
    Canio,
    Triboulet,
    Yorick,
    Chicot,
    Perkeo,
    J_L_END,

    J_END,

    // Vouchers
    V_BEGIN,
    Overstock,
    Overstock_Plus,
    Clearance_Sale,
    Liquidation,
    Hone,
    Glow_Up,
    Reroll_Surplus,
    Reroll_Glut,
    Crystal_Ball,
    Omen_Globe,
    Telescope,
    Observatory,
    Grabber,
    Nacho_Tong,
    Wasteful,
    Recyclomancy,
    Tarot_Merchant,
    Tarot_Tycoon,
    Planet_Merchant,
    Planet_Tycoon,
    Seed_Money,
    Money_Tree,
    Blank,
    Antimatter,
    Magic_Trick,
    Illusion,
    Hieroglyph,
    Petroglyph,
    Directors_Cut,
    Retcon,
    Paint_Brush,
    Palette,
    V_END,

    // Tarots
    T_BEGIN,
    The_Fool,
    The_Magician,
    The_High_Priestess,
    The_Empress,
    The_Emperor,
    The_Hierophant,
    The_Lovers,
    The_Chariot,
    Justice,
    The_Hermit,
    The_Wheel_of_Fortune,
    Strength,
    The_Hanged_Man,
    Death,
    Temperance,
    The_Devil,
    The_Tower,
    The_Star,
    The_Moon,
    The_Sun,
    Judgement,
    The_World,
    T_END,

    // Planets
    P_BEGIN,
    Mercury,
    Venus,
    Earth,
    Mars,
    Jupiter,
    Saturn,
    Uranus,
    Neptune,
    Pluto,
    Planet_X,
    Ceres,
    Eris,
    P_END,

    // Hands
    H_BEGIN,
    Pair,
    Three_of_a_Kind,
    Full_House,
    Four_of_a_Kind,
    Flush,
    Straight,
    Two_Pair,
    Straight_Flush,
    High_Card,
    Five_of_a_Kind,
    Flush_House,
    Flush_Five,
    H_END,

    // Spectrals
    S_BEGIN,
    Familiar,
    Grim,
    Incantation,
    Talisman,
    Aura,
    Wraith,
    Sigil,
    Ouija,
    Ectoplasm,
    Immolate,
    Ankh,
    Deja_Vu,
    Hex,
    Trance,
    Medium,
    Cryptid,
    The_Soul,
    Black_Hole,
    S_END,

    // Enhancements
    ENHANCEMENT_BEGIN,
    No_Enhancement,
    Bonus_Card,
    Mult_Card,
    Wild_Card,
    Glass_Card,
    Steel_Card,
    Stone_Card,
    Gold_Card,
    Lucky_Card,
    ENHANCEMENT_END,

    // Seals
    SEAL_BEGIN,
    No_Seal,
    Gold_Seal,
    Red_Seal,
    Blue_Seal,
    Purple_Seal,
    SEAL_END,

    // Editions
    E_BEGIN,
    No_Edition,
    Foil,
    Holographic,
    Polychrome,
    Negative,
    E_END,

    // Booster Packs
    PACK_BEGIN,
    Arcana_Pack,
    Jumbo_Arcana_Pack,
    Mega_Arcana_Pack,
    Celestial_Pack,
    Jumbo_Celestial_Pack,
    Mega_Celestial_Pack,
    Standard_Pack,
    Jumbo_Standard_Pack,
    Mega_Standard_Pack,
    Buffoon_Pack,
    Jumbo_Buffoon_Pack,
    Mega_Buffoon_Pack,
    Spectral_Pack,
    Jumbo_Spectral_Pack,
    Mega_Spectral_Pack,
    PACK_END,

    // Tags
    TAG_BEGIN,
    Uncommon_Tag,
    Rare_Tag,
    Negative_Tag,
    Foil_Tag,
    Holographic_Tag,
    Polychrome_Tag,
    Investment_Tag,
    Voucher_Tag,
    Boss_Tag,
    Standard_Tag,
    Charm_Tag,
    Meteor_Tag,
    Buffoon_Tag,
    Handy_Tag,
    Garbage_Tag,
    Ethereal_Tag,
    Coupon_Tag,
    Double_Tag,
    Juggle_Tag,
    D6_Tag,
    Top_up_Tag,
    Speed_Tag,
    Orbital_Tag,
    Economy_Tag,
    TAG_END,

    // Blinds
    B_BEGIN,
    Small_Blind,
    Big_Blind,
    The_Hook,
    The_Ox,
    The_House,
    The_Wall,
    The_Wheel,
    The_Arm,
    The_Club,
    The_Fish,
    The_Psychic,
    The_Goad,
    The_Water,
    The_Window,
    The_Manacle,
    The_Eye,
    The_Mouth,
    The_Plant,
    The_Serpent,
    The_Pillar,
    The_Needle,
    The_Head,
    The_Tooth,
    The_Flint,
    The_Mark,
    B_F_BEGIN,
    Amber_Acorn,
    Verdant_Leaf,
    Violet_Vessel,
    Crimson_Heart,
    Cerulean_Bell,
    B_F_END,
    B_END,

    // Suits
    SUIT_BEGIN,
    Hearts,
    Clubs,
    Diamonds,
    Spades,
    SUIT_END,

    // Ranks
    RANK_BEGIN,
    _2,
    _3,
    _4,
    _5,
    _6,
    _7,
    _8,
    _9,
    _10,
    Jack,
    Queen,
    King,
    Ace,
    RANK_END,

    // Cards
    C_BEGIN,
    C_2,
    C_3,
    C_4,
    C_5,
    C_6,
    C_7,
    C_8,
    C_9,
    C_A,
    C_J,
    C_K,
    C_Q,
    C_T,
    D_2,
    D_3,
    D_4,
    D_5,
    D_6,
    D_7,
    D_8,
    D_9,
    D_A,
    D_J,
    D_K,
    D_Q,
    D_T,
    H_2,
    H_3,
    H_4,
    H_5,
    H_6,
    H_7,
    H_8,
    H_9,
    H_A,
    H_J,
    H_K,
    H_Q,
    H_T,
    S_2,
    S_3,
    S_4,
    S_5,
    S_6,
    S_7,
    S_8,
    S_9,
    S_A,
    S_J,
    S_K,
    S_Q,
    S_T,
    C_END,

    // Decks
    D_BEGIN,
    Red_Deck,
    Blue_Deck,
    Yellow_Deck,
    Green_Deck,
    Black_Deck,
    Magic_Deck,
    Nebula_Deck,
    Ghost_Deck,
    Abandoned_Deck,
    Checkered_Deck,
    Zodiac_Deck,
    Painted_Deck,
    Anaglyph_Deck,
    Plasma_Deck,
    Erratic_Deck,
    Challenge_Deck,
    D_END,

    // Challenges
    CHAL_BEGIN,
    The_Omelette,
    _15_Minute_City,
    Rich_get_Richer,
    On_a_Knifes_Edge,
    X_ray_Vision,
    Mad_World,
    Luxury_Tax,
    Non_Perishable,
    Medusa,
    Double_or_Nothing,
    Typecast,
    Inflation,
    Bram_Poker,
    Fragile,
    Monolith,
    Blast_Off,
    Five_Card_Draw,
    Golden_Needle,
    Cruelty,
    Jokerless,
    CHAL_END,

    //Stakes
    STAKE_BEGIN,
    White_Stake,
    Red_Stake,
    Green_Stake,
    Black_Stake,
    Blue_Stake,
    Purple_Stake,
    Orange_Stake,
    Gold_Stake,
    STAKE_END,

    ITEMS_END
} item;

typedef enum ShopItemType {
    ItemType_Joker,
    ItemType_Tarot,
    ItemType_Planet,
    ItemType_PlayingCard,
    ItemType_Spectral
} itemtype;

typedef struct ShopInstance {
    double jokerRate;
    double tarotRate;
    double planetRate;
    double playingCardRate;
    double spectralRate;
} shop;

typedef enum JokerRarity {
    Rarity_Common,
    Rarity_Uncommon,
    Rarity_Rare,
    Rarity_Legendary
} rarity;

typedef struct JokerStickers {
    bool eternal;
    bool perishable;
    bool rental;
} jokerstickers;

// Object that contains a joker and its rarity.
typedef struct JokerData {
    item joker;
    rarity _rarity;
    item edition;
    jokerstickers stickers;
} jokerdata;

typedef struct ShopItem {
    itemtype type;
    item value;
    jokerdata joker;
} shopitem;

typedef struct WeightedItem {
    item _item;
    double weight;
} weighteditem;
typedef struct Pack {
    item type;
    int size;
    int choices;
} pack;

// Contains settings used for different packs
// Level means level of the voucher, level 0 -> no voucher, level 1 -> base voucher, level 2 -> upgraded voucher
typedef struct InstanceParameters {
    item deck;
    item stake;
    bool vouchers[32];
    bool showman;

    item deckCards[52];
    int deckSize;
    int handSize;
} instance_params;

// math.random

typedef union DoubleLong {
    double d;
    ulong ul;
} dbllong;

typedef struct LuaRandom {
    ulong state[4];
    dbllong out;
} lrandom;

// ----------

typedef struct Seed {
    ulong data[8];
    int len;
} seed;

typedef enum NodeType {
    N_Type,
    N_Source,
    N_Ante,
    N_Resample
} ntype;

typedef struct RNGInfo {
    ntype nodeTypes[4];
    int nodeValues[4];
    int depth;
    double rngState;
} rnginfo;

typedef struct Cache {
    #ifdef CACHE_SIZE
    rnginfo nodes[CACHE_SIZE];
    #else
    rnginfo nodes[64];
    #endif
    bool generatedFirstPack;
    int nextFreeNode;
} cache;

// Instance
typedef struct GameInstance {
    seed seed;
    cache rngCache;
    double hashedSeed;
    lrandom rng;
    bool locked[ITEMS_END];
    instance_params params;
} instance;

typedef struct Card {
    item base;
    item enhancement;
    item edition;
    item seal;
} card;

// RNG Cache
typedef enum RandomType {
    R_Joker_Common,
    R_Joker_Uncommon,
    R_Joker_Rare,
    R_Joker_Legendary,
    R_Joker_Rarity,
    R_Joker_Edition,
    R_Misprint,
    R_Standard_Has_Enhancement,
    R_Enhancement,
    R_Card,
    R_Standard_Edition,
    R_Standard_Has_Seal,
    R_Standard_Seal,
    R_Shop_Pack,
    R_Tarot,
    R_Spectral,
    R_Tags,
    R_Shuffle_New_Round,
    R_Card_Type,
    R_Planet,
    R_Lucky_Mult,
    R_Lucky_Money,
    R_Sigil,
    R_Ouija,
    R_Wheel_of_Fortune,
    R_Gros_Michel,
    R_Cavendish,
    R_Voucher,
    R_Voucher_Tag,
    R_Orbital_Tag,
    R_Soul,
    R_Erratic,
    R_Eternal,
    R_Perishable,
    R_Eternal_Perishable,
    R_Eternal_Perishable_Pack,
    R_Rental,
    R_Rental_Pack,
    R_Boss,
    R_END
} rtype;

typedef enum RNGSource {
    S_Shop,
    S_Emperor,
    S_High_Priestess,
    S_Judgement,
    S_Wraith,
    S_Arcana,
    S_Celestial,
    S_Spectral,
    S_Standard,
    S_Buffoon,
    S_Vagabond,
    S_Superposition,
    S_Seance,
    S_Sixth_Sense,
    S_Top_Up,
    S_Rare_Tag,
    S_Uncommon_Tag,
    S_Blue_Seal,
    S_Purple_Seal,
    S_8_Ball,
    S_Soul,
    S_Riff_Raff,
    S_Cartomancer,
    S_Null,
    SOURCE_END
} rsrc;

#define V_AT_LEAST(v1,v2,v3,v4) \
        (VER1 > v1) || \
        (VER1 == v1 && ((VER2 > v2) ||\
        (VER2 == v2 && ((VER3 > v3) ||\
        (VER3 == v3 && VER4 >= v4)))))

#define V_AT_MOST(v1,v2,v3,v4) \
        (VER1 < v1) || \
        (VER1 == v1 && ((VER2 < v2) ||\
        (VER2 == v2 && ((VER3 < v3) ||\
        (VER3 == v3 && VER4 <= v4)))))

// Cache
text type_str(int x);
text source_str(int x);
text resample_str(int x);
text node_str(ntype nt, int x);
int init_node(cache* c, ntype nodeTypes[], int nodeValues[], int depth);
// Debug
void print_item(item i);
// Functions
bool is_voucher_active(instance* inst, item voucher);
void activate_voucher(instance* inst, item voucher);
item standard_enhancement(instance* inst, int ante);
item standard_base(instance* inst, int ante);
item standard_edition(instance* inst, int ante);
item standard_seal(instance* inst, int ante);
card standard_card(instance* inst, int ante);
item next_pack(instance* inst, int ante);
item next_tarot(instance* inst, rsrc itemSource, int ante, bool soulable);
item next_planet(instance* inst, rsrc itemSource, int ante, bool soulable);
item next_spectral(instance* inst, rsrc itemSource, int ante, bool soulable);
rarity next_joker_rarity(instance* inst, rsrc itemSource, int ante);
item next_joker_edition(instance* inst, rsrc itemSource, int ante);
jokerdata next_joker_with_info(instance* inst, rsrc itemSource, int ante);
item next_joker(instance* inst, rsrc itemSource, int ante);
shop get_shop_instance(instance* inst);
double get_total_rate(shop shopInstance);
itemtype get_item_type(shop shopInstance, double generatedValue);
shopitem next_shop_item(instance* inst, int ante);
item shop_joker(instance* inst, int ante);
item shop_tarot(instance* inst, int ante);
item shop_planet(instance* inst, int ante);
item next_tag(instance* inst, int ante);
void arcana_pack(item out[], int size, instance* inst, int ante);
void celestial_pack(item out[], int size, instance* inst, int ante);
void spectral_pack(item out[], int size, instance* inst, int ante);
void buffoon_pack(item out[], int size, instance* inst, int ante);
void buffoon_pack_detailed(jokerdata out[], int size, instance* inst, int ante);
void buffoon_pack_editions(item out[], int size, instance* inst, int ante);
void standard_pack(card out[], int size, instance* inst, int ante);
int misprint(instance* inst);
bool lucky_mult(instance* inst);
bool lucky_money(instance* inst);
item sigil_suit(instance* inst);
item ouija_rank(instance* inst);
item wheel_of_fortune_edition(instance* inst);
bool gros_michel_extinct(instance* inst);
bool cavendish_extinct(instance* inst);
item next_voucher(instance* inst, int ante);
item next_voucher_from_tag(instance* inst, int ante);
item next_boss(instance* inst, int ante);
void sort_deck(item array[], int arrayLength);
void init_erratic_deck(instance* inst);
void copy_cards(item to[], const item from[]);
void init_deck(instance* inst, item out[]);
void set_deck(instance* inst, item deck);
void set_stake(instance* inst, item stake) ;
void shuffle_deck(instance* inst, item deck[], int ante);
void next_hand_drawn(instance* inst, item hand[], int ante);
item next_orbital_tag(instance* inst);
// Instance
instance i_new(seed s);
double get_node_child(instance* inst, ntype nts[], int ids[], int num);
double random(instance* inst, ntype nts[], int ids[], int num);
double random_simple(instance* inst, rtype rt);
ulong randint(instance* inst, ntype nts[], int ids[], int num, ulong min, ulong max);
item randchoice(instance* inst, ntype nts[], int ids[], int num, const item items[]);
item randchoice_common(instance* inst, rtype rngType, rsrc src, int ante, const item items[]);
item randchoice_resample(instance* inst, rtype rngType, rsrc src, int ante, const item items[], int resampleNum);
item randchoice_simple(instance* inst, rtype rngType, const item items[]);
item randchoice_dynamic(instance* inst, ntype nts[], int ids[], int num, item items[]);
item randchoice_simple_dynamic(instance* inst, rtype rngType, item items[]);
void randlist(item out[], int size, instance* inst, rtype rngType, rsrc src, int ante, const item items[]);
item randweightedchoice(instance* inst, ntype nts[], int ids[], int num, const weighteditem items[]);
void init_locks(instance* inst, int ante, bool fresh_profile, bool fresh_run);
void init_unlocks(instance* inst, int ante, bool fresh_profile);
// Items
pack pack_info(item pack);
item suit(item card);
item rank(item card);
item next_rank(item rank);
item suit_repr(item suit);
item rank_repr(item rank);
item from_rank_suit(item rank, item suit);
// Seed
int s_char_num(char c);
seed s_new_empty();
seed s_new(const char* str_seed, int seed_size);
seed s_new_c8(char8 str_seed);
char s_char_at(seed* s, int c);
llong s_tell(seed* s);
text s_to_string(seed* s);
void s_print(seed* s);
void s_print_rank(seed* s, llong rank);
void s_next(seed* s);
void s_skip(seed* s, llong n);
// Util
inline text init_text(const char* str, int len) {
    text t;
    for (int i = 0; i < len; i++){
        t.str[i] = str[i];
    }
    t.len = len;
    t.str[t.len] = '\0';
    return t;
}
inline void set_text_length(text* t, int len) {
    t->len = len;
    t->str[t->len] = '\0';
}
text text_concat(text a, text b);
void print_text(text x);
double fract(double f);
double pseudohash(text s);
double pseudohash8(char8 s);
unsigned int lsh32(unsigned int x, size_t l);
unsigned int rsh32(unsigned int x, size_t r);
double roundDigits(double f, int d);
double pseudohash_legacy(const char* s, size_t stringLen);
double c16_pseudohash_legacy(char16 s);
char16 c8_as_c16(char8 c8);
void _randint(lrandom* lr);
void randdblmem(lrandom* lr);
lrandom randomseed(double d);
double l_random(lrandom* lr);
ulong l_randint(lrandom* lr, ulong min, ulong max);
text int_to_str(int x);

// Define some constants for important game version splits
#if V_AT_MOST(0,9999,9999,9999)
    #define DEMO
#endif

extern const char SEEDCHARS[];
extern const int NUM_CHARS;
extern const item ENHANCEMENTS[];
extern const item CARDS[];
extern const item SUITS[];
extern const item RANKS[];
extern const item DECK_ORDER[];
extern const item ABANDONED_DECK_ORDER[];
extern const item CHECKERED_DECK_ORDER[];
extern const weighteditem PACKS[];
extern const pack PACK_INFO[];
extern const item TAROTS[];
extern const item PLANETS[];
extern const item LEGENDARY_JOKERS[];
extern const item COMMON_JOKERS[];
extern const item UNCOMMON_JOKERS[];
extern const item RARE_JOKERS[];
extern const item VOUCHERS[];
extern const item SPECTRALS[];
extern const item TAGS[];
extern const item BOSSES[];
extern const item POKER_HANDS[];

#endif // IMMOLATE_H