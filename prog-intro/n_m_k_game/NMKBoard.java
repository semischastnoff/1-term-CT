package n_m_k_game;

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

        cells[move.getRow()][move.getColumn()] = move.getValue();

        if (checkCol() || checkRow()) {
            return Result.WIN;
        }

        if (checkDiagonal1() || checkDiagonal2()) {
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

    private boolean checkCol() {
        for (int r = 0; r < n; r++) {
            int cntCol = 0;
            if (cells[r][0] == turn) {
                cntCol++;
            }
            for (int c = 1; c < m; c++) {
                if (cells[r][c] == turn && (cells[r][c - 1] == turn || cells[r][c - 1] == Cell.E)) {
                    cntCol++;
                }
            }
            if (cntCol == k) {
                return true;
            }
        }
        return false;
    }

    private boolean checkRow() {
        for (int c = 0; c < m; c++) {
            int cntRow = 0;
            if (cells[0][c] == turn) {
                cntRow++;
            }
            for (int r = 1; r < n; r++) {
                if (cells[r][c] == turn && (cells[r - 1][c] == turn || cells[r - 1][c] == Cell.E)) {
                    cntRow++;
                }
            }
            if (cntRow == k) {
                return true;
            }
        }
        return false;
    }

    private boolean checkDiagonal1() {
        for (int startRow = n - 1; startRow >= 0; startRow--) {
            int cntDiag = 0;
            if (cells[startRow][0] == turn) {
                cntDiag++;
            }
            int r = startRow + 1, c = 1;
            while (r < n && c < m) {
                if (cells[r][c] == turn && (cells[r - 1][c - 1] == turn|| cells[r - 1][c - 1] == Cell.E)) {
                    cntDiag++;
                }
                r++;
                c++;
            }
            if (cntDiag == k) {
                return true;
            }
        }
        return false;
    }

    private boolean checkDiagonal2() {
        for (int startRow = 0; startRow < n; startRow++) {
            int cntDiag = 0;
            if (cells[startRow][0] == turn) {
                cntDiag++;
            }
            int r = startRow - 1, c = 1;
            while (r >= 0 && c < m) {
                if (cells[r][c] == turn && (cells[r + 1][c - 1] == turn || cells[r + 1][c - 1] == Cell.E)) {
                    cntDiag++;
                }
                r--;
                c++;
            }
            if (cntDiag == k) {
                return true;
            }
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
