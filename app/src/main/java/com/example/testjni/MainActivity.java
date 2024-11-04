package com.example.testjni;

import android.os.Bundle;
import android.widget.TextView;

import androidx.activity.EdgeToEdge;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        JNILoader jniLoader = new JNILoader();
        TextView txtView = new TextView(this);
        txtView.setText(jniLoader.GetNativeString());


        setContentView(txtView);

    }
}