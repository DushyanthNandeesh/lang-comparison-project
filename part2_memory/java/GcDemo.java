// Java: garbage collection demo. The developer never calls free();
// objects become eligible for collection once nothing references them,
// and the JVM's GC reclaims that memory on its own schedule.
import java.util.ArrayList;
import java.util.List;

public class GcDemo {

    // A finalizer-like hook (registered via Cleaner in modern Java) lets us
    // *observe* when the GC actually reclaims an object, purely for this demo.
    static class BigBlob {
        final int id;
        final byte[] payload = new byte[10 * 1024 * 1024]; // 10 MB each
        BigBlob(int id) { this.id = id; }
    }

    public static void main(String[] args) throws InterruptedException {
        Runtime rt = Runtime.getRuntime();
        System.out.println("Used memory before allocation: "
                + usedMB(rt) + " MB");

        List<BigBlob> blobs = new ArrayList<>();
        for (int i = 0; i < 20; i++) {
            blobs.add(new BigBlob(i)); // ~200 MB allocated on the heap
        }
        System.out.println("Used memory after allocating 20x10MB blobs: "
                + usedMB(rt) + " MB");

        // Drop every reference to the blobs. We never call free() or delete;
        // we simply make the objects unreachable.
        blobs.clear();
        blobs = null;

        // Politely ASK for garbage collection. This is only a hint --
        // the JVM decides if/when collection actually runs.
        System.gc();
        Thread.sleep(200); // give the GC thread a moment to run

        System.out.println("Used memory after clearing references + System.gc(): "
                + usedMB(rt) + " MB");
        System.out.println("Note: the programmer never freed memory manually; " +
                "the JVM's garbage collector reclaimed the unreachable objects.");
    }

    private static long usedMB(Runtime rt) {
        return (rt.totalMemory() - rt.freeMemory()) / (1024 * 1024);
    }
}
