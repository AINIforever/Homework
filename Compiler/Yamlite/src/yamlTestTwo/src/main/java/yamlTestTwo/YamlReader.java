package yamlTestTwo;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

public class YamlReader {
    private BufferedReader code;
    private int lineNo;
    private String lineText;

    public YamlReader(String fileStr) {
        try {
            code = new BufferedReader(new FileReader(fileStr));
            lineNo = 0;
        }catch (IOException e){
            e.printStackTrace();
        }
    }

    public String nextLine(){
        String temp = "";
        try{
            temp = code.readLine();
        }catch (IOException e){
            e.printStackTrace();
        }
        if(temp!=null) {
            temp = temp + "\n";
            lineNo++;
        }
        lineText = temp;
        return lineText;
    }

    public int getLineNo() {
        return lineNo;
    }

    public String getLineText() {
        return lineText;
    }
}
