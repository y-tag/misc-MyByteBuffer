package myorg.common;

import com.google.common.hash.Hashing;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;

public class MyByteBuffer {

    private ByteBuffer byteBuffer;

    public MyByteBuffer() {
        this(128, ByteOrder.LITTLE_ENDIAN);
    }

    public MyByteBuffer(int capacity, ByteOrder bo) {
        this.byteBuffer = ByteBuffer.allocate(capacity);
        this.byteBuffer.order(bo);
    }

    public MyByteBuffer clear() {
        byteBuffer.clear();
        return this;
    }

    public int hashCode() {
        return hashCode(0);
    }

    public int hashCode(int seed) {
        byte[] array = byteBuffer.array();
        int len = byteBuffer.position();
        
        return Hashing.murmur3_32(seed).hashBytes(array, 0, len).asInt();
    }

    public MyByteBuffer addString(String value) {
        byteBuffer.put(value.getBytes());
        return this;
    }

    public MyByteBuffer addInt(int value) {
        byteBuffer.putInt(value);
        return this;
    }

    public MyByteBuffer addLong(long value) {
        byteBuffer.putLong(value);
        return this;
    }

    public MyByteBuffer addFloat(float value) {
        byteBuffer.putFloat(value);
        return this;
    }

    public MyByteBuffer addDouble(double value) {
        byteBuffer.putDouble(value);
        return this;
    }

}
