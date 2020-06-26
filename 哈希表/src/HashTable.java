import java.util.TreeMap;

// 每一个object类都有hashcode 方法，默认hashcode 是根据对象的地址进行返回
// 如果不重写hashcode ，那么不同对象的 hashcode 是不一样的
// 当产生hash冲突的时候，需要辨别2个对象是否相等，因为重写了hashcode 方法，所以返回的hashcode 是相同的
//  辨别的方法是使用equals
//  需要利用反射重写equals 函数，然后具体判断属性是否相同
//  hash不需要比较
// 该实现中利用treemap 解决哈希冲突
public class HashTable<K,V> {

    private static final int upperTol = 10 ;
    private static final int lowerTol = 2 ;
    private static final int initCapacity = 7 ;

    private TreeMap<K,V>[] hashtable ;
    private int M;  // 地址空间数量
    private int size ; // 插入的元素的总个数

    public HashTable(int M){
        this.M = M;
        size = 0;
        hashtable = new TreeMap[M];

        for(int i = 0 ; i < M ;i++){
            hashtable[i] = new TreeMap<>();
        }
    }

    public HashTable(){
        this(initCapacity);
    }

    // 根据hashcode将值产生索引
    private int hash(K key){
        return (key.hashCode() & 0x7fffffff) % M;
    }

    public int getSize(){
        return size;
    }


    // 添加元素
    public void add(K key,V value){

        TreeMap<K,V> map = hashtable[hash(key)];

        if(map.containsKey(key))
            map.put(key,value);
        else {
            map.put(key,value);
            size++;

            if(size >= upperTol*M)
                resize(2*M);
        }

    }

    // 删除元素
    public V remove(K key){
        TreeMap<K,V> map = hashtable[hash(key)];

        V ret = null;

        if(map.containsKey(key)){
            ret = map.remove(key);
            size--;

            if(size < lowerTol * M && M/2 >= initCapacity)
                resize(M/2);
        }

        return ret;
    }


    // 进行修改
    public void set(K key , V value){

        TreeMap<K,V> map = hashtable[hash(key)];

        if(!map.containsKey(key))
            throw new IllegalArgumentException(key + " doesn't exist!");

        map.put(key,value);
    }

    // 判断哈希表中是否有键的存在
    public boolean contains(K key){
       return hashtable[hash(key)].containsKey(key);
    }

    // 返回键对应的值
    public V get (K key){
        return  hashtable[hash(key)].get(key);
    }

    // 进行扩容和缩容
    private void resize(int newM){
            TreeMap<K,V> [] newHashTable = new TreeMap[newM];

            for(int i= 0 ; i< newM ; i++)
                newHashTable[i] = new TreeMap<>();

            int oldM = M;

            this.M = newM ;

            for(int i= 0 ; i< oldM ; i++){
                TreeMap<K,V> map = hashtable[i];

                for(K key : map.keySet())
                    newHashTable[hash(key)].put(key,map.get(key));
            }

            this.hashtable = newHashTable;
    }


    public static void main(String[] args) {

      int arr[] = {7,7,8,54,3,2,21,2,3,3,4455};

      HashTable<Integer ,Integer> hash = new HashTable<>();

      for(int i =0 ; i< arr.length ; i++){

          if(hash.contains(arr[i])){
              hash.set(arr[i],hash.get(arr[i]) + 1);
          }else {
              hash.add(arr[i],1);
          }
      }

        System.out.println(hash.get(7));

        System.out.println(hash.get(2));

        System.out.println(hash.get(3));

    }

}
