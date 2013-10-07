package myorg.common;

import java.io.File;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;
import java.util.Random;

import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import org.junit.Assert.*;

import static org.junit.Assert.assertEquals;

import myorg.common.MyByteBuffer;

public class MyByteBufferTest {

    @BeforeClass
    public static void setUpClass() throws Exception {
    }

    @AfterClass
    public static void tearDownClass() throws Exception {
    }
 
    @Before
    public void setUp() throws Exception {
    }

    @After
    public void tearDown() throws Exception {
    }

    @Test
    public void testHashCodeForString() throws IOException {
        int seed = 12345;
        int hash = 0;
        MyByteBuffer bb = new MyByteBuffer();

        bb.clear();
        hash = bb.addString("").hashCode(seed);
        assertEquals(1011272156, hash);

        bb.clear();
        hash = bb.addString("abcde:123456789").hashCode(seed);
        assertEquals(2115837011, hash);

        bb.clear();
        hash = bb.addString("term:foobarhoge").hashCode(seed);
        assertEquals(1746195674, hash);

        bb.clear();
        hash = bb.addString("term:ふーばーほげ").hashCode(seed);
        assertEquals(933544832, hash);

        bb.clear();
        hash = bb.addString("キー:バリュー").hashCode(seed);
        assertEquals(385955771, hash);
    }

    @Test
    public void testHashCodeForMix() throws IOException {
        int seed = 12345;
        int hash = 0;
        MyByteBuffer bb = new MyByteBuffer();

        bb.clear();
        hash = bb.addString("abc").addInt(12345).addString("def").hashCode(seed);
        assertEquals(629088618, hash);

        bb.clear();
        hash = bb.addString("key").addInt(12345).addString("value").addFloat(0.789f).hashCode(seed);
        assertEquals(506168901, hash);

        bb.clear();
        hash = bb.addString("きー").addLong(1234567890123L).addString("バリュー").addDouble(0.123).hashCode(seed);
        assertEquals(68316556, hash);
    }
}
