import com.sun.scenario.effect.Merge;

import java.util.Objects;

public class SegmentTree <E> {

    private E[] tree ; // 线段树

    private E[] data ; // 数据

    private Merger<E> merge ;

    // 进行融合
    public SegmentTree(E[] arr , Merger<E> merge){

        this.merge = merge ;

        data = (E[])new Object[arr.length];

        for(int i = 0 ; i < arr.length ; i++){

            data[i] = arr[i];

        }

         tree = (E[])new Object[4 * arr.length];

        buildSegmentTree(0,0,data.length - 1);

    }

    // 在treeIndex 的位置 创建 表示 区间 [l...r] 的 线段树
    // treeIndex 是 tree数组的下标，表示这个下标的tree数组的值说管控的 data数组的区间 l 到 r
    private void buildSegmentTree(int treeIndex , int l , int r) {

        if(l == r){
            tree[treeIndex] = data[l];
            return;
        }
        int leftTreeIndex = leftChild(treeIndex);

        int rightTreeIndex = rightChild(treeIndex);

        int mid = l + (r - l) /2 ;

        buildSegmentTree(leftTreeIndex,l,mid);

        buildSegmentTree(rightTreeIndex,mid + 1 ,r);

        tree[treeIndex] = merge.merge(tree[leftTreeIndex] , tree[rightTreeIndex] ) ;

    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的左孩子节点的索引
    private int leftChild(int index){

        return 2*index + 1;

    }

    // 返回完全二叉树的数组表示中，一个索引所表示的元素的右孩子节点的索引
    private int rightChild(int index){

        return 2* index + 2;

    }

    public int getSize(){
        return data.length ;
    }

    public E get(int index){

        if(index < 0 || index >= data.length)
            throw new IllegalArgumentException("Index is illegal.");

        return data[index];
    }

    // 返回区间[queryL.queryR]的值
    public E query(int queryL , int queryR){

        if(queryL < 0 || queryL >= data.length || queryR < 0 || queryR >= data.length || queryL > queryR)
            throw new IllegalArgumentException("index is illegal.");

        return query(0,0,data.length - 1 ,queryL , queryR);
    }

    // queryL和queryR 是 查询 data 数组的下标区间
    // l和r 是 data 数组 的 下标
    // 在以treeID为根的线段树中[l...r]的范围里，搜索区间[queryL...queryR]的值
    private E query(int treeIndex , int l , int r , int queryL , int queryR){

        if(l == queryL && r == queryR){
            return tree[treeIndex];
        }

        int mid = l + (r - l) /2 ;

        int leftTreeIndex = leftChild(treeIndex);

        int rightTreeIndex = rightChild(treeIndex);

        if(queryL >= mid + 1)
            return query(rightTreeIndex,mid + 1 , r , queryL,queryR);
        else if(queryR <= mid)
            return query(leftTreeIndex,l,mid,queryL,queryR);
        else{

            E leftResult =  query(leftTreeIndex,l,mid,queryL,mid);
            E rightResult = query(rightTreeIndex,mid + 1, r,mid+ 1 ,queryR);

            return merge.merge(leftResult,rightResult);
        }

    }

    // 将index位置的值，更新为e
    public void set(int index , E e){

        if(index < 0 || index >= data.length)
            throw new IllegalArgumentException("Index is illegal");

        data[index] = e;

        set(0,0,data.length - 1,index,e);
    }

        // 在以treeIndex为根的线段树中更新index的值为e
        // 使用了回溯
        private void set(int treeIndex , int l , int r , int index , E e) {

            if(l == r){
                tree[treeIndex] = e ;
                return;
            }

            int mid = l + (r - l) /2 ;

            int leftTreeIndex = leftChild(treeIndex);

            int rightTreeIndex = rightChild(treeIndex);

            if(index >= mid + 1)
                set(rightTreeIndex,mid + 1 ,r,index,e);
            else
                set(leftTreeIndex,l,mid,index,e);

            tree[treeIndex] = merge.merge(tree[leftTreeIndex],tree[rightTreeIndex]);

    }


    @Override
    public String toString(){

        StringBuffer res = new StringBuffer();

        res.append('[');

        for(int i =0 ; i < tree.length ; i++){

            if(tree[i] != null)
                res.append(tree[i]);
            else
                res.append("null");

            if( i != tree.length - 1){
                    res.append(",");
            }
        }

        res.append("]");

        return res.toString();
    }

}
