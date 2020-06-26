
// 利用二分搜索树实现集合set
//  往集合中添加元素 ，删除元素 ，判断是否包含元素 ，获得集合的容量 ，判断集合是否为空
// 时间 复杂度 o(log(n))
// 没有重复元素，实现去重
// BST 树的 时间 复杂度 和 BST 树 的高度 有关

import com.BinaryTree.BinarySearchTree;

public class BSTSet <E extends  Comparable<E>> implements Set<E>{

    private BinarySearchTree<E> bst ;

    public BSTSet(){
        bst = new BinarySearchTree<>();
    }

    @Override
    public void add(E e) {
            bst.add(e);
    }

    @Override
    public void remove(E e) {
            bst.remove(e);
    }

    @Override
    public boolean contains(E e) {
        return bst.contains(e);
    }

    @Override
    public int getSize() {
        return bst.size();
    }

    @Override
    public boolean isEmpty() {
        return bst.isEmpty();
    }
}
