#pragma once 

class Piece {

    public: 

        enum PieceType {

            Pions,
            Tour,
            Cavalier,
            Fous,
            Reine,
            Roi

        };

        virtual PieceType GetTypePiece() const = 0;

        virtual ~Piece() = default;

};