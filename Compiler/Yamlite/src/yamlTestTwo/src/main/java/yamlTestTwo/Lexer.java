package yamlTestTwo;

import java.util.ArrayList;


import static yamlTestTwo.TokenType.*;

public class Lexer {
    private YamlReader code;
    private ArrayList<Token> tokenList;
    private static int pos;

    private static String[] REGEXS = {
            "^(0|-?[1-9]\\d*)$",  //int
            "^((0\\.0)|-?[1-9]\\d*\\.\\d*)$",  //float
            "^(\\d\\.\\d*(e|E)(\\+|-)?\\d*)$",  //bigdecimal
            "^[a-zA-Z](([0-9a-zA-Z_]*[0-9a-zA-Z])|[0-9a-zA-Z])?$",   //identifier
    };

//    private Token token;

    public Lexer(String fileStr) {
        code = new YamlReader(fileStr);
        tokenList = new ArrayList<>();
    }

    public void parse() throws LexicalException {
        while (code.nextLine() != null) {
            checkLine();
        }
    }

    public ArrayList<Token> getTokenList(){
        return this.tokenList;
    }

    private void checkLine() throws LexicalException {
        String lineText = code.getLineText();
        int layer = 0;
        int spaces = 0;
        int index = 0;
        int pos = 0;
        while (lineText.startsWith(" ")) {
            spaces++;
            pos++;
            lineText = lineText.substring(1);
        }
        if (spaces % 2 != 0) {
            throw new LexicalException("indent error", code.getLineNo(), spaces);
        }
        layer = spaces / 2;

        if(lineText.startsWith("#")){
            return ;
        }

        if (lineText.startsWith("-")) {
            lineText = lineText.substring(1);
            if (index==lineText.length()||lineText.charAt(index) == '\n') {
                Token token = new Token(ARRAY).addData("-").addLayer(layer,true);
                tokenList.add(token);
            }
            else if (lineText.charAt(index) == ' ') {
                index++;
                while (index < lineText.length() && lineText.charAt(index) != '#' && lineText.charAt(index) != '\n') {
                    index++;
                }
                String content = lineText.substring(1, index);
                content = content.trim();
                addToken(content, layer, true, pos);

                if(lineText.charAt(index)=='#'){
                    return;
                }
            }
        }
        if(lineText.contains(":")){
            String[] separate = lineText.split(":",2);
            String key = separate[0];
            String value = separate[1];
            pos += key.length();

            if(value.contains("#")){
                value = value.split("#",2)[0];
            }
            if(value.startsWith(" ")&&!value.startsWith("  ")){
                if(value.trim().length()>0&&!value.trim().equals("\n")){
//                    if(value.trim().startsWith("\"") && value.trim().endsWith("\"")) {
                        Token token = new Token(IDENTIFIER).addData(key).addLayer(layer,layer>0);
                        tokenList.add(token);
//                    }
                    addToken(value.trim(), layer, layer>0,pos);
                }
            }else {
                Token token = new Token(ARRAY).addData(key).addLayer(layer,layer>0);
                tokenList.add(token);
            }
        }
        else if(lineText.equals("\n")){
            return;
        }
    }

    private void addToken(String content, int level, boolean isAraayElement, int pos) throws LexicalException{
        if(content.matches(REGEXS[0])){
            tokenList.add(new Token(INT).addData(content).addLayer(level,isAraayElement));
        }else if(content.matches(REGEXS[1])){
            tokenList.add(new Token(DOUBLE).addData(content).addLayer(level,isAraayElement));
        }else if(content.matches(REGEXS[2])) {
            tokenList.add(new Token(BIGDECIMAL).addData(content).addLayer(level,isAraayElement));
        }else if(content.equals("true")||content.equals("false")){
            tokenList.add(new Token(BOOL).addData(content).addLayer(level,isAraayElement));
        }else{
            if(!content.startsWith("\"")){
                pos += 2;
                throw new LexicalException("expect <\">", code.getLineNo(),pos);
            }
            if(!content.endsWith("\"")){
                pos += 2 + content.length();
                throw new LexicalException("expect <\">", code.getLineNo(),pos);
            }
            tokenList.add(new Token(STRING).addData(content).addLayer(level,isAraayElement));
        }
    }

}