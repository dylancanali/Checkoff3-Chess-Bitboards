#include <stdint.h>
#include <stdio.h>

int main(void)
{
    /* Each bit represents one square on the chessboard.
       A1 is bit 0, B1 is bit 1, and B2 is bit 9. */

    uint64_t white_pawns = 0x000000000000FF00ULL;
    uint64_t white_rooks = 0x0000000000000081ULL;
    uint64_t black_pawns = 0x00FF000000000000ULL;

    /* 1. AND (&): Check whether a white pawn is on B2. */
    uint64_t b2 = 1ULL << 9;

    printf("1. Is there a white pawn on B2?\n");
    if (white_pawns & b2) {
        printf("Yes!\n\n");
    } else {
        printf("No.\n\n");
    }

    /* 2. OR (|): Combine the piece bitboards. */
    uint64_t occupied = white_pawns | white_rooks | black_pawns;

    printf("2. Combined board: 0x%016llX\n",
           (unsigned long long)occupied);

    /* 3. NOT (~): Find the empty squares. */
    uint64_t empty = ~occupied;

    printf("3. Empty squares:  0x%016llX\n\n",
           (unsigned long long)empty);

    /* 4. Left shift (<<): Move all white pawns forward one rank.
       Each rank has 8 squares, so shift by 8. */
    uint64_t next_rank = white_pawns << 8;

    printf("4. White pawns moved forward: 0x%016llX\n\n",
           (unsigned long long)next_rank);

    /* 5. Clear one square and set another to move a pawn.
       Move a pawn from E2 (bit 12) to E4 (bit 28). */
    uint64_t from = 1ULL << 12;
    uint64_t to = 1ULL << 28;

    white_pawns = white_pawns & ~from; /* Clear E2. */
    white_pawns = white_pawns | to;    /* Set E4. */

    printf("5. White pawns after moving E2 to E4: ");
    printf("0x%016llX\n\n", (unsigned long long)white_pawns);

    /* 6. Knight example: a knight on B1 can move to C3.
       Check C3 using a bit mask. */
    uint64_t knight_move = 1ULL << 18; /* C3 is bit 18. */
    uint64_t knight_position = 1ULL << 1; /* B1 is bit 1. */

    printf("6. Knight example:\n");
    printf("A knight on B1 can move to C3 (an L-shaped move).\n");
    printf("B1 bitboard: 0x%016llX\n",
           (unsigned long long)knight_position);
    printf("C3 mask:     0x%016llX\n",
           (unsigned long long)knight_move);

    return 0;
}