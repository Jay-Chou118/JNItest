package com.example.jnitestdemo;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

import com.example.jnitestdemo.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'jnitestdemo' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }


    private ActivityMainBinding binding;

    /**
     * A native method that is implemented by the 'jnitestdemo' native library,
     * which is packaged with this application.
     */
    public native String Java_com_example_jnitestdemo_NativeLib_stringFromJNI(String url);


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        // Example of a call to a native method
        TextView tv = binding.sampleText;
//        String result = Java_com_example_jnitestdemo_NativeLib_stringFromJNI("http://www.google.com");
        String result = Java_com_example_jnitestdemo_NativeLib_stringFromJNI("https://www.baidu.com");
        tv.setText(result);


        Log.d("MainActivity", "RRRRRRRRResult from JNI: " + result);
    }

}