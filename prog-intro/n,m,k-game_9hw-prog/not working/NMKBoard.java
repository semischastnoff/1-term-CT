package game;

import java.util.Arrays;
import java.util.Map;

public class NMKBoard implements Board, Position {
    private static final Map<Cell, Character> SYM = Map.of(
            Cell.X, 'X',
            Cell.O, 'O',
            Cell.E, '.'
    );

    private final Cell[][] cells;
    private Cell turn;
    private final int n, m, k;
    private int moveRow, moveCol;

    public NMKBoard(int n, int m, int k) {
        this.n = n;
        this.m = m;
        this.k = k;
        this.cells = new Cell[n][m];
        for (Cell[] row : cells) {
            Arrays.fill(row, Cell.E);
        }
        turn = Cell.X;
    }

    @Override
    public Position getPosition() {
        return this;
    }

    @Override
    public Cell getCell() {
        return turn;
    }

    @Override
    public Result makeMove(final Move move) {
        if (!isValid(move)) {
            return Result.LOSE;
        }

        moveRow = move.getRow();
        moveCol = move.getColumn();

        cells[moveRow][moveCol] = move.getValue();

        if (checkWin()) {
            return Result.WIN;
        }

        if (isNowhereToGo()) {
            return Result.DRAW;
        }

        turn = turn == Cell.X ? Cell.O : Cell.X;
        return Result.UNKNOWN;
    }

    private boolean isNowhereToGo() {
        int cntEmpty = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (cells[r][c] == Cell.E) {
                    cntEmpty++;
                }
            }
        }
        return (cntEmpty == 0);
    }

    private boolean checkWin() {
        int cntCol = 0;
        int cntRow = 0;
        int cntDiagM = 0;
        int cntDiagA = 0;
        //check right/down/diagonal
        int r = moveRow, c = moveCol;
        if (cells[r][c] == turn) {
            cntCol++;
            cntRow++;
            cntDiagA++;
            cntDiagM++;
        }
        r++;
        c++;
        while (r < n && c < m && r > 0 && c > 0
                && (cells[r][moveCol] == cells[r - 1][moveCol]
                || cells[moveRow][c] == cells[moveRow][c - 1]
                || cells[r][c] == cells[r - 1][c - 1]
                || cells[n - r - 1][c] == cells[n - r][c - 1])) {

            if (cells[r][moveCol] == cells[r - 1][moveCol]) cntCol++;
            if (cells[moveRow][c] == cells[moveRow][c - 1]) cntRow++;
            if (cells[r][c] == cells[r - 1][c - 1]) cntDiagM++;
            if (cells[n - r - 1][c] == cells[n - r][c - 1]) cntDiagA++;
            r++;
            c++;
        }
        //check left/up/diagonal
        r = moveRow - 1;
        c = moveCol - 1;
        while (r >= 0 && c >= 0 && r < n - 1 && c < m - 1
                && (cells[r][moveCol] == cells[r + 1][moveCol]
                || cells[moveRow][c] == cells[moveRow][c + 1]
                || cells[r][c] == cells[r + 1][c + 1]
                || cells[n - r - 1][c] == cells[n - r][c - 1])) {

            if (cells[r][moveCol] == cells[r + 1][moveCol]) cntCol++;
            if (cells[moveRow][c] == cells[moveRow][c + 1]) cntRow++;
            if (cells[r][c] == cells[r + 1][c + 1]) cntDiagM++;
            if (cells[n - r - 1][c] == cells[n - r][c - 1]) cntDiagA++;
            r--;
            c--;
        }
        if (cntCol == k || cntRow == k || cntDiagM == k || cntDiagA == k) {
            return true;
        }
        return false;
    }

    @Override
    public boolean isValid(final Move move) {
        return 0 <= move.getRow() && move.getRow() < n
                && 0 <= move.getColumn() && move.getColumn() < m
                && cells[move.getRow()][move.getColumn()] == Cell.E
                && turn == getCell();
    }

    @Override
    public Cell getCell(final int r, final int c) {
        return cells[r][c];
    }

    @Override
    public String toString() {
        StringBuilder sb = new StringBuilder();
        sb.append('\\');
        for (int col = 0; col < m; col++) {
            sb.append(col);
        }
        for (int r = 0; r < n; r++) {
            sb.append("\n");
            sb.append(r);
            for (int c = 0; c < m; c++) {
                sb.append(SYM.get(cells[r][c]));
            }
        }
        return sb.toString();
    }
}
