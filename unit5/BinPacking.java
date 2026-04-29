import java.util.*;

public class BinPacking {
    static class Bin {
        int capacity;
        int currentSize;

        Bin(int capacity) {
            this.capacity = capacity;
            this.currentSize = 0;
        }

        boolean canFit(int item) {
            return currentSize + item <= capacity;
        }

        void addItem(int item) {
            currentSize += item;
        }
    }

    public static int firstFit(int[] items, int binCapacity) {
        List<Bin> bins = new ArrayList<>();
        for (int item : items) {
            boolean placed = false;
            for (Bin bin : bins) {
                if (bin.canFit(item)) {
                    bin.addItem(item);
                    placed = true;
                    break;
                }
            }
            if (!placed) {
                Bin newBin = new Bin(binCapacity);
                newBin.addItem(item);
                bins.add(newBin);
            }
        }
        return bins.size();
    }

    public static void main(String[] args) {
        int[] items = {4, 8, 1, 4, 2, 1};
        int binCapacity = 10;
        int minBins = firstFit(items, binCapacity);
        System.out.println("Minimum number of bins required: " + minBins);
    }
}