#include <iostream>
#include <string>
#include <bitset>

const int BOARD_SIZE = 64;

// Piece values in FEN notation
const char PAWN = 'P';
const char KNIGHT = 'N';
const char BISHOP = 'B';
const char ROOK = 'R';
const char QUEEN = 'Q';
const char KING = 'K';

// Bitboard for each piece type
std::bitset<BOARD_SIZE> pawn_bb;
std::bitset<BOARD_SIZE> knight_bb;
std::bitset<BOARD_SIZE> bishop_bb;
std::bitset<BOARD_SIZE> rook_bb;
std::bitset<BOARD_SIZE> queen_bb;
std::bitset<BOARD_SIZE> king_bb;

// Convert FEN notation to index in bitboard
int fen_to_index(int row, int col) {
    return BOARD_SIZE - (row * 8) - col - 1;
}

void parse_fen_notation(const std::string& fen) {
    int row = 7;
    int col = 0;

    // Loop through each character in the FEN string
    for (char c : fen) {
        if (c == '/') {
            // Move to the next row
            row--;
            col = 0;
        } else if (isdigit(c)) {
            // Move the column pointer based on the number of empty squares
            col += c - '0';
        } else {
            // Set the corresponding bit in the bitboard
            int index = fen_to_index(row, col);
            switch (c) {
                case PAWN:
                    pawn_bb.set(index);
                    break;
                case KNIGHT:
                    knight_bb.set(index);
                    break;
                case BISHOP:
                    bishop_bb.set(index);
                    break;
                case ROOK:
                    rook_bb.set(index);
                    break;
                case QUEEN:
                    queen_bb.set(index);
                    break;
                case KING:
                    king_bb.set(index);
                    break;
            }
            col++;
        }
    }
}

int main() {
    std::string fen = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR";
    parse_fen_notation(fen);

    // Print the bitboards for each piece type
    std::cout << "Pawns:    " << pawn_bb << std::endl;
    std::cout << "Knights:  " << knight_bb << std::endl;
    std::cout << "Bishops:  " << bishop_bb << std::endl;
    std::cout << "Rooks:    " << rook_bb << std::endl;
    std::cout << "Queens:   " << queen_bb << std::endl;
    std::cout << "Kings:    " << king_bb << std::endl;
    return 0;
}