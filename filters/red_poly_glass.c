// Red Poly Glass Cards
#include "immolate.h"

llong filter(instance* inst) {
    int numCards = 0;
    // Check if either pack is a Standard Pack - and which has the most cards
    pack pack1 = pack_info(next_pack(inst, 1));
    pack pack2 = pack_info(next_pack(inst, 1));

    if (pack1.type == Standard_Pack) numCards = pack1.size;
    if (pack2.type == Standard_Pack && pack2.size > numCards) numCards = pack2.size;
    if (numCards == 0) return 0;
    if (!(pack1.choices == 2 || pack2.choices == 2)) return 0;
    
    // Check if one of the cards satisfies all of the conditions needed
    int found_total = 0;
    for (int i = 0; i < numCards; i++) {
        card _card = standard_card(inst, 1);
        if (_card.enhancement != Glass_Card) continue;
        if (_card.edition != Polychrome) continue;
        if (_card.seal != Red_Seal) continue;
        found_total++;
    }
    return found_total;
}