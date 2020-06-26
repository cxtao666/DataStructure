import java.util.ArrayList;

public class AVLTree<K extends Comparable<K>,V> {

    private class Node{
        public K key ;
        public V value ;
        public Node left , right ;
        public int height ;

        public Node(K key , V value){
           this.key = key;
           this.value = value ;
            left = null;
            right = null ;
            height = 1 ;
        }
    }

    private Node root ;
    private int size ;

    public AVLTree(){
        root = null;
        size = 0 ;
    }

    // 获得节点的node的高度
    private int getHeight(Node node){
        if(node == null)
            return 0;
        return node.height ;
    }

    // 获得节点node 的平衡因子
    private int getBalanceFactor(Node node){
           if(node == null){
               return  0;
           }
           return getHeight(node.left) - getHeight(node.right);
    }

    private void inOrder(Node node , ArrayList<K> keys){

        if(node == null) return;

        inOrder(node.left , keys);

        keys.add(node.key);

        inOrder(node.right,keys);
    }

    // 判断该二叉树是否是一颗二分搜索树
    public boolean isBST(){

        ArrayList<K> keys = new ArrayList<>();

        inOrder(root,keys);

        for(int i = 1 ; i < keys.size() ; i++){
            if(keys.get(i-1).compareTo(keys.get(i)) >  0) return false;
        }

        return true ;
    }

    // 判断该二叉树是否是一颗平衡二叉树
    public boolean isBalanced(){
            return isBalanced(root);
    }

    // 判断以node 为根的二叉树是否是一颗平衡二叉树，递归算法
    private boolean isBalanced(Node node){

        if(node == null)  return true ;

        int balanceFactor = getBalanceFactor(node);

        if(Math.abs(balanceFactor) > 1)  return false;

        return isBalanced(node.left) && isBalanced(node.right);
    }



    // 向二分搜索树中添加新的元素(key,value)

    public void add(K key, V value) {
        root = addNode(root, key ,value);
    }

    //向以node 为根的二分搜索树中插入元素 （key，value） ，递归算法
    // 返回插入新节点后二分搜索树的根
    // 并在添加的过程中使用左旋转和右旋转实现AVL树
    private Node addNode(Node node , K key , V value){

        if(node == null){
            size++;
            return new Node(key,value);
        }

        if(key.compareTo(node.key) < 0 ){
            node.left = addNode(node.left , key,value);

        }else if(key.compareTo(node.key) > 0 ){
            node.right = addNode(node.right,key,value);
        }else{
            node.value = value ;
        }

        // 进行回溯
        // 更新height
        node.height = 1 + Math.max(getHeight(node.left),getHeight(node.right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(node);

        // 保持AVL树自平衡
        /**   if(Math.abs(balanceFactor) > 1){
            System.out.println("unbalanced : " + balanceFactor);
        } **/

        // 平衡维护
        // 右旋
        // 左子树的平衡因子是大于等于0的
        // LL
        if(balanceFactor > 1 && getBalanceFactor(node.left) >= 0)
           return rightRotate(node) ;

        // 左旋 右子树的平衡因子是小于等于0的
        // RR
        if(balanceFactor < -1 && getBalanceFactor(node.right) <= 0 ){
            return leftRotate(node);
        }

        //LR
        if(balanceFactor > 1 && getBalanceFactor(node.left) < 0){

            node.left = leftRotate(node.left);
            return rightRotate(node);

        }

        //RL
        if(balanceFactor < -1 && getBalanceFactor(node.right) > 0){
           node.right = rightRotate(node.right);
           return leftRotate(node);

        }


        return node ;
    }

    // 进行右旋转
    private Node rightRotate(Node y){

        Node x  = y.left ;
        Node T3 = x.right;
        // 向右旋转的过程
        x.right = y ;
        y.left = T3 ;

        //更新height
        y.height = Math.max(getHeight(y.left),getHeight(y.right)) + 1;
        x.height = Math.max(getHeight(x.left),getHeight(x.right)) + 1 ;
        return x ;
    }

    // 进行左旋转
    private Node leftRotate(Node y){
           Node x = y.right;
           Node T2 = x.left;

           // 向左旋转
            x.left = y ;
            y.right = T2;

            //更新height
        y.height = Math.max(getHeight(y.left),getHeight(y.right)) + 1;
        x.height = Math.max(getHeight(x.left),getHeight(x.right)) + 1;

        return  x ;
    }

    // 返回以node 为根的二分搜索树的key最小值所在的节点
    private Node minimum(Node node){
        if(node.left == null){
            return node;
        }
        return minimum(node.left);
    }

    // 删除掉以node为根的二分搜索树中key最小值的节点
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


    // 从二分搜索树中删除键为key 对应的节点

    public V remove(K key){

        Node node = getNode(root,key);

        if(node != null){
            root = remove(root,key);
            return node.value;
        }

        return  null ;

    }


    private Node remove(Node node,K key) {

        if(node == null){
            return null;
        }

        Node retNode ;

        if(key.compareTo(node.key) < 0){
            node.left = remove(node.left ,key);
            retNode = node;

          //  return node ;
        }
        else if(key.compareTo(node.key) > 0){
            node.right = remove(node.right,key);
            retNode = node ;

           // return  node ;
        }
        else {

            // 待删除节点的左子树为空的情况
            if(node.left == null){
                Node rightNode = node.right;
                node.right = null ;
                size-- ;
                retNode = rightNode;
            }
            // 待删除的节点的右子树为空的情况
            else if(node.right == null){

                Node leftNode = node.left;
                node.left = null ;
                size-- ;
                retNode = leftNode;

            }
            else {

                // 待删除结点左右子树均不为空的情况
                // 找到待删除节点右子树的最小节点
                /// 用这个节点顶替待删除结点的位置
                Node successor = minimum(node.right);
                successor.right = remove(node.right, successor.key); // 会进入前面的判断 左子树是空的，或右子树是空的

                successor.left = node.left;

                node.left = node.right = null;

                retNode = successor;
            }
        }

        // 如果删除的节点是叶子节点，那么retNode可能出现是null的情况
        if(retNode == null){
            return  null ;
        }

        // 维护平衡

        // 进行回溯
        // 更新height
        retNode.height = 1 + Math.max(getHeight(retNode.left),getHeight(retNode.right));

        // 计算平衡因子
        int balanceFactor = getBalanceFactor(retNode);

        // 保持AVL树自平衡
        /**   if(Math.abs(balanceFactor) > 1){
         System.out.println("unbalanced : " + balanceFactor);
         } **/

        // 平衡维护
        // 右旋
        // 左子树的平衡因子是大于等于0的
        // LL
        if(balanceFactor > 1 && getBalanceFactor(retNode.left) >= 0)
            return rightRotate(retNode) ;

        // 左旋 右子树的平衡因子是小于等于0的
        // RR
        if(balanceFactor < -1 && getBalanceFactor(retNode.right) <= 0 ){
            return leftRotate(retNode);
        }

        //LR
        if(balanceFactor > 1 && getBalanceFactor(retNode.left) < 0){

            retNode.left = leftRotate(retNode.left);
            return rightRotate(retNode);

        }

        //RL
        if(balanceFactor < -1 && getBalanceFactor(retNode.right) > 0){
            retNode.right = rightRotate(retNode.right);
            return leftRotate(retNode);

        }

        return retNode;

    }

    // 返回以node为根节点的二分搜索树中，key所在的节点
    private  Node getNode(Node node, K key){

        if(node == null){
            return null;
        }

        if(key.compareTo(node.key) == 0) return node ;
        else if( key.compareTo(node.key) < 0 ) return getNode(node.left,key);
        else {
            return getNode(node.right,key);
        }
    }


    public boolean contains(K key) {
        return getNode(root,key) != null;
    }


    public V get(K key) {

        Node node =  getNode(root,key);

        return node == null ? null : node.value;
    }


    public void set(K key, V newValue) {

        // node 是个指针
            Node node = getNode(root,key);

            if(node == null)
                throw new IllegalArgumentException(key + " doesn't exist!");

           node.value = newValue ;
    }


    public boolean isEmpty() {
        return size == 0;
    }


    public int getSize() {
        return size;
    }
}
