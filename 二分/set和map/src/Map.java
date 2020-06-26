public interface Map <K,V> {

    void add(K key,V value); // 添加键值对
    V remove(K key); // 删除键值对
    boolean contains(K key); // 判断map 中是否包含该 键
    V get(K key);  // 获取 value;
    void set( K key ,V newValue) ; // 修改 value 的值
    boolean isEmpty() ;  // 判断 map 是否为空
    int getSize() ; // 返回键值对的个数

}
