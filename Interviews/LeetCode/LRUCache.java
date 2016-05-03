public class LRUCache {
    int cur,total;
    TreeMap<Long, Integer> timeToKey;
    HashMap<Integer, Integer> keyToValue;
    HashMap<Integer, Long> keyToTime;
    long clock;
    public LRUCache(int capacity) {
        this.total = capacity;
        this.cur = 0;
        this.timeToKey = new TreeMap<Long,Integer>();
        this.keyToValue = new HashMap<Integer,Integer>();
        this.keyToTime = new HashMap<Integer,Long>();
        this.clock = 0;
    }
    
    private void remove (int key) {
        if(!keyToValue.containsKey(key))
            return;
            
        long time = keyToTime.get(key);
        timeToKey.remove(time);
        keyToTime.remove(key);
        int val = keyToValue.get(key);
        cur -= val;
        keyToValue.remove(key);
    }
    
    public int get(int key) {
        if(keyToValue.containsKey(key)) {
            long timeLastUsed = keyToTime.get(key);
            timeToKey.remove(timeLastUsed);
            timeToKey.put(clock, key);
            keyToTime.remove(key);
            keyToTime.put(key, clock++);
            
            return keyToValue.get(key);
        }
        
        return -1;
    }
    
    public void set(int key, int value) {
        remove(key);
        if(cur + value > total && !timeToKey.isEmpty()) {
            int lru = timeToKey.firstEntry().getValue();
            remove(lru);
        }
        
        cur += value;
        timeToKey.put(clock, key);
        keyToTime.put(key, clock++);
        keyToValue.put(key, value);
    }
}
