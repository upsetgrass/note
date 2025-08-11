#!/usr/bin/env python3
import threading
import time
from collections import deque

class ProducerConsumer:
    def __init__(self, max_size=5):
        self.queue = deque()
        self.max_size = max_size
        self.lock = threading.Lock()
        self.not_full = threading.Condition(self.lock)
        self.not_empty = threading.Condition(self.lock)
    
    def produce(self, item):
        with self.lock:
            # 等待队列未满
            while len(self.queue) >= self.max_size:
                print(f"队列已满，生产者等待...")
                self.not_full.wait()
            
            # 生产数据
            self.queue.append(item)
            print(f"生产: {item}，当前队列: {list(self.queue)}")
            
            # 通知消费者可以消费
            self.not_empty.notify()
    
    def consume(self):
        with self.lock:
            # 等待队列非空
            while not self.queue:
                print(f"队列为空，消费者等待...")
                self.not_empty.wait()
            
            # 消费数据
            item = self.queue.popleft()
            print(f"消费: {item}，剩余队列: {list(self.queue)}")
            
            # 通知生产者可以生产
            self.not_full.notify()
        return item

def producer_task(pc, num_items):
    for i in range(num_items):
        pc.produce(i)
        time.sleep(0.1)  # 模拟生产耗时

def consumer_task(pc, num_items):
    for _ in range(num_items):
        pc.consume()
        time.sleep(0.2)  # 模拟消费耗时

if __name__ == "__main__":
    pc = ProducerConsumer(max_size=5)
    num_operations = 10
    
    producer = threading.Thread(
        target=producer_task,
        args=(pc, num_operations),
        name="Producer"
    )
    
    consumer = threading.Thread(
        target=consumer_task,
        args=(pc, num_operations),
        name="Consumer"
    )

    producer.start()
    consumer.start()
    
    producer.join()
    consumer.join()
    
    print("所有操作完成")
