#include "immolate.h"

// Helper functions

pack pack_info(item pack) {
    return PACK_INFO[pack-Arcana_Pack];
}

item suit(item card) {
    if (card <= C_T) return Clubs;
    if (card <= D_T) return Diamonds;
    if (card <= H_T) return Hearts;
    return Spades;
}
item rank(item card) {
    if (card % 13 == C_2 % 13) return _2;
    if (card % 13 == C_3 % 13) return _3;
    if (card % 13 == C_4 % 13) return _4;
    if (card % 13 == C_5 % 13) return _5;
    if (card % 13 == C_6 % 13) return _6;
    if (card % 13 == C_7 % 13) return _7;
    if (card % 13 == C_8 % 13) return _8;
    if (card % 13 == C_9 % 13) return _9;
    if (card % 13 == C_T % 13) return _10;
    if (card % 13 == C_J % 13) return Jack;
    if (card % 13 == C_Q % 13) return Queen;
    if (card % 13 == C_K % 13) return King;
    return Ace;
}
item next_rank(item rank) {
    if (rank == Ace) return _2;
    return (int)rank+1;
}
item suit_repr(item suit) {
    if (suit == Clubs) return C_2;
    if (suit == Diamonds) return D_2;
    if (suit == Hearts) return H_2;
    return S_2;
}
item rank_repr(item rank) {
    if (rank == _2) return C_2;
    if (rank == _3) return C_3;
    if (rank == _4) return C_4;
    if (rank == _5) return C_5;
    if (rank == _6) return C_6;
    if (rank == _7) return C_7;
    if (rank == _8) return C_8;
    if (rank == _9) return C_9;
    if (rank == _10) return C_T;
    if (rank == Jack) return C_J;
    if (rank == Queen) return C_Q;
    if (rank == King) return C_K;
    return C_A;
}

item from_rank_suit(item rank, item suit) {
    return suit_repr(suit) + rank_repr(rank) - C_2;
}