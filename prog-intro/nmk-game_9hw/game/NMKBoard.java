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
    private int cntCol, cntRow, cntDiagM, cntDiagA;
    private int row, col;
    private int empty;

    public NMKBoard(int n, int m, int k) {
        this.n = n;
        this.m = m;
        this.k = k;
        this.empty = n * m;
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

        this.row = move.getRow();
        this.col = move.getColumn();
        cells[row][col] = move.getValue();
        empty--;

        if (hasWon()) {
            return Result.WIN;
        }

        if (empty <= 0) {
            return Result.DRAW;
        }

        turn = (turn == Cell.X) ? Cell.O : Cell.X;
        return Result.UNKNOWN;
    }

    private boolean hasWon() {
        return checkWays(1, 0) == k || checkWays(0, 1) == k || checkWays(1, 1) == k || checkWays(1, -1) == k;
    }

    private int checkWays(int i, int j) {
        int res = 0;
        if (cells[row][col] == turn) {
            res++;
        }
        int r = row + i;
        int c = col + j;
        while (insdeOfBoard(r, c) && cells[r][c] == turn) {
            r += i;
            c += j;
            res++;
        }
        r = row - i;
        c = col - j;
        while (insdeOfBoard(r, c) && cells[r][c] == turn) {
            r -= i;
            c -= j;
            res++;
        }
        return res;
    }

    private boolean insdeOfBoard(int r, int c) {
        return (r < n && c < m) && (r >= 0 && c >= 0);
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
        int add = cntAddR(0);
        sb.append(" ".repeat(add + 1));
        for (int col = 0; col < m; col++) {
            int addC = cntAddC(col);
            int addM = cntAddC(m);
            sb.append(col);
            sb.append(" ".repeat(addM - addC + 1));
        }
        for (int r = 0; r < n; r++) {
            sb.append("\n");
            sb.append(r);
            int addR = cntAddR(r);
            sb.append(" ".repeat(addR + 1));
            for (int c = 0; c < m; c++) {
                sb.append(SYM.get(cells[r][c]));
                int addC = cntAddC(m);
                sb.append(" ".repeat(addC));
            }
        }
        return sb.toString();
    }

    private int cntAddC(int c) {
        int x = 1;
        int res = 0;
        while (c / x > 0) {
            x *= 10;
            res++;
        }
        return (c == 0) ? 1 : res;
    }

    private int cntAddR(int r) {
        int cntN = 0, cntR = 0;
        int x = 1;
        while (n / x > 0) {
            if (r / x > 0) {
                cntR++;
            }
            x *= 10;
            cntN++;
        }
        return (r == 0) ? cntN - cntR - 1 : cntN - cntR;
    }
}
