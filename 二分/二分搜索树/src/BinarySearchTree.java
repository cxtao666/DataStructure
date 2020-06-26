package com.BinaryTree;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Stack;

// 实现一个二分搜索树
// 类型E 要具有可比较性
// 二分搜索树不包含重复元素
// 泛型比较大小，C++中得运算符重载了
// 所以这里用了 compareTo 函数 ， 让E 继承 至 Comparable
// 包括添加结点，删除结点，遍历 ，查找结点 ， 求 size
// 二分搜索树的顺序性
public class BinarySearchTree<E extends Comparable<E>> {

    private class Node{
        public E e ;
        public Node left , right ;

        public Node(E e){
            this.e = e ;
            left = null;
            right = null;
        }
    }

    // 存储根节点
    private Node root ;

    // 节点的数量
    private int size ;

    public BinarySearchTree(){
        root = null ;
        size = 0 ;
    }

    public int size(){
        return size ;
    }

    public boolean isEmpty(){
        return size == 0 ;
    }


    // 用递归实现二分搜索树添加元素e
    // 递归的开销比非递归的开销大
    // 如果二分搜索树退化成链表，递归容易导致栈溢出
    public void add(E e){

        // 使用add 方法
      /**  if(root == null){
            root = new Node(e);
            size++;
        }
        else {
            add(root,e);
        } **/

      // 使用 addnode 方法
        root = addNode(root,e);
    }

    // 向以node 为根 的 二分搜索树 中插入 元素 E，递归算法
    private void add(Node node ,E e) {

        if (e.equals(node.e)) return;
            // e小于node.e 表明要插入左子树
        else if (e.compareTo(node.e) < 0) {
            if (node.left == null) {
                node.left = new Node(e);
                size++;
                return;
            } else {
                add(node.left, e);
            }
            // e 小于 node.e 表明要插入右子树
        } else if (e.compareTo(node.e) > 0) {

            if (node.right == null) {
                node.right = new Node(e);
                size++;
                return;
            } else {
                add(node.right, e);
            }
        }
    }

    //向以node 为根的二分搜索树中插入元素e ，递归算法
    // 返回插入新节点后二分搜索树的根
    private Node addNode(Node node , E e){

        if(node == null){
            size++;
            return new Node(e);
        }

        if(e.compareTo(node.e) < 0 ){
           node.left = addNode(node.left , e);
        }else if(e.compareTo(node.e) > 0 ){
           node.right = addNode(node.right,e);
        }

        return node ;

    }

    // 看二分搜索树中是否包含元素e
    public boolean contains(E e){

        return contains(root,e);
    }

    // 看以node 为根的二分搜索树中是否包含元素 e，递归算法
    private boolean contains(Node node , E e){

        if(node == null){
            return false ;
        }

        if(e.compareTo(node.e) == 0){
            return true ;
        }else if(e.compareTo(node.e) < 0){
            return contains(node.left ,e);
        }else {
           return  contains(node.right,e);
        }

    }

    // 遍历二叉搜索树
    // 深度优先遍历

    // 前序遍历
    public void preOrder(){
        preOrder(root);
    }

    private void preOrder(Node node){

        if(node == null) return;

        System.out.println(node.e);

        preOrder(node.left);
        preOrder(node.right);
    }


    // 先序遍历的非递归写法
    // 压入左孩子和右孩子，左孩子在栈顶，访问左孩子，把左孩子弹出栈，然后再把左孩子的2个儿子按左孩子在上，右孩子在下的顺序压入栈，以此类推
    // 非递归实现要比递归实现更加复杂
    public void preOrderNR(){

        Stack<Node> stack = new Stack<>();

       stack.push(root);


       while (!stack.isEmpty()){
            Node cur = stack.pop();
           System.out.println(cur.e);

           if(cur.right != null)
           stack.push(cur.right);

           if(cur.left != null)
           stack.push(cur.left);
       }
    }



    // 使用中序遍历打印出来的是顺序排序
    public void inOrder(){
        inOrder(root);
    }

    private void inOrder(Node node){

        if(node == null) return;

        inOrder(node.left);

        System.out.println(node.e);

        inOrder(node.right);
    }

    // 使用后序遍历遍历二叉查找树
    public void endOrder(){
        endOrder(root);
    }

    private void endOrder(Node node){

        if(node == null) return;

        endOrder(node.left);

        endOrder(node.right);

        System.out.println(node.e);
    }

    // 层序遍历
    // 广度优先遍历
    public void levelOrder(){

        Queue<Node> queue = new LinkedList<>();

        queue.add(root);

        while (!queue.isEmpty()){

            Node cur = queue.remove();

            System.out.println(cur.e);

            if(cur.left  != null)
                queue.add(cur.left);
            if(cur.right != null)
                queue.add(cur.right);
        }
    }

    // 删除二分搜索树的最小值和最大值
    // 向左走不动就是最小值
     // 向右走，走不动就是最大值

    // 寻找二分搜索树的最小元素
    public E minimum(){
            if(size == 0)
                throw new IllegalArgumentException("BST is empty!");
          return   minimum(root).e;
    }

    private Node minimum(Node node){
        if(node.left == null){
            return node;
        }
        return minimum(node.left);
    }

    // 寻找二分搜索树的最大元素
    public E maximum(){
        if(size == 0)
            throw new IllegalArgumentException("BST is empty!");
        return   maximum(root).e;
    }

    private Node maximum(Node node){
        if(node.right == null){
            return node;
        }
        return maximum(node.right);
    }

    // 如果是叶子节点，直接删除就好
    // 最小值有右子树，把右子树挂到父节点的左子树
    // 最大值有左子树，把左子树挂到父节点的右子树

    // 删除二分搜索树的最小值
    public E removeMin(){
        E ret = minimum();

        root = removeMin(root);

        return ret;
    }

    // 删除掉以node为根的二分搜索树中的最小节点
    // 返回删除节点后新的二分搜索树的根
    private Node removeMin(Node node){

        if(node.left == null){
            Node rightNode = node.right;
            node.right = null;
            size--;
            return rightNode;
        }

        node.left = removeMin(node.left);

        return node;
    }

    // 删除二分搜索树的最大值
    public E removeMax(){
        E ret = maximum();

        root = removeMax(root);

        return ret;
    }

    private Node removeMax(Node node){

        if(node.right == null){
            Node leftNode = node.left;
            node.left = null;
            size--;
            return leftNode;
        }

        node.right = removeMax(node.right);

        return node;
    }

    // 删除左右都有的节点
    // 后继节点
    // 找右子树中最小的那个节点
    // 前驱节点
    // 找左子树中最大的那个节点
    // 用来代替要删除的结点

    public void remove(E e){
        remove(root,e);
    }


    // 删除掉以node 为根的二分搜索树中 值 为 e的 节点，递归算法
    // 返回删除节点后新的二分搜索树的根
    private Node remove (Node node , E e){

        if(node == null){
            return null;
        }

        if(e.compareTo(node.e) < 0){
           node.left = remove(node.left ,e);
            return node ;
        }
        else if(e.compareTo(node.e) > 0){
            node.right = remove(node.right,e);
              return  node ;
        }
        else {

            // 待删除节点的左子树为空的情况
            if(node.left == null){
                Node rightNode = node.right;
                node.right = null ;
                size-- ;
                return rightNode;
            }

            // 待删除的节点的右子树为空的情况
            if(node.right == null){

                Node leftNode = node.left;
                node.left = null ;
                size-- ;
                return leftNode;

            };

            // 待删除结点左右子树均不为空的情况
            // 找到待删除节点右子树的最小节点
            /// 用这个节点顶替待删除结点的位置
            Node successor = minimum(node.right);
            successor.right = removeMin(node.right);

            successor.left = node.left;

            node.left = node.right = null;

            return successor;
        }

    }


}
