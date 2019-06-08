#include "PrototypesProject.h"

MultipleSingleSourceMovesList *FindAllPossiblePlayerMoves(Board board, player player)
{
	MultipleSingleSourceMovesList *MulSrcMovesLoLst;
	SingleSourceMovesTree *srcMoveTr;
	checkersPos src;
	SingleSourceMovesList *srcMovesLst;
	makeEmptyList(&srcMovesLst);
	makeEmptyLoList(&MulSrcMovesLoLst); // Making an empty list of possible moves lists

	for (src.row = 'A'; src.row <='H'; src.row++)
	{
		for (src.col = '1'; src.col <= '8'; src.col++)
		{
			if (board[(int)(src.row) - 'A'][src.col - '0' - 1] == player) // Player recognized as the desired one
			{						   // Updating source structure

				// Finding a single source moves tree
				srcMoveTr = FindSingleSourceMoves(board, &src);
				// Find the best move in each single source moves tree
				srcMovesLst = FindSingleSourceOptimalMove(srcMoveTr);
				// Building a List of best moves for each source
				insertLolNodeToTail(MulSrcMovesLoLst, createLolNode(srcMovesLst, NULL));
			}
		}
	}
	return (MulSrcMovesLoLst); // Returning the
}
