public class Main {

    public static void main(String[] args) {

        Integer [] nums = {-2,0,3,-5,2,1};

        SegmentTree<Integer> segmentTree = new SegmentTree<>(nums, new Merger<Integer>() {
            @Override
            public Integer merge(Integer a, Integer b) {
                return a + b;
            }
        });

        System.out.println(segmentTree.query(0,2));
        System.out.println(segmentTree.query(2,5));
        System.out.println(segmentTree.query(0,5));
    }
}
