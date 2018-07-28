package yamlTestTwo;

import yamlTestTwo.JsonUtil.*;

import java.util.ArrayList;
import java.util.Iterator;

public class Parser {
    private Lexer lexer;

    private JsonFormat jsonFormat;

    private Token token;

    private Iterator<Token> it1;

    public JsonFormat parseYaml(String yamlFile) throws LexicalException {
        init(yamlFile);
        lexer.parse();
        ArrayList<Token> tokenArrayList = lexer.getTokenList();
        it1 = lexer.getTokenList().iterator();
        token = it1.next();


        if(token.getTokenType() == TokenType.IDENTIFIER || token.getTokenType() == TokenType.ARRAY && token.toString() != "-"){
            jsonFormat = parseObject(0);
        }
        if (token.getTokenType() == TokenType.ARRAY) {
            jsonFormat = parseArray(0);
        }

//        jsonFormat = parseObject(0);


        return jsonFormat;
    }

    /**
     * Init class before parse json token
     * @param yamlFile
     */
    private void init(String yamlFile) {
        lexer = new Lexer(yamlFile);

        token = null;
        jsonFormat = null;
    }

    private JsonObject parseObject(int layer) throws LexicalException {
        JsonObject object = new JsonObject();

        String key;
        JsonValue value = null;

        for (;;) {

            key = token.toString();

            if (token.getTokenType() == TokenType.IDENTIFIER && layer > token.getLayer()){
                return object;
            }
            layer = token.getLayer();

            if (token.getTokenType() == TokenType.ARRAY){
                value = parseArray(layer);
                if(layer == token.getLayer()){
                    object.addKeyAndValue(key,value);
                    if(!it1.hasNext()){
                        return object;
                    }

                }
            }


            if(token.getTokenType() == TokenType.IDENTIFIER && !token.getIsArrayElement()){
//                object = parseObject(layer);
                key = token.toString();
            }

            if(it1.hasNext()){
                token = it1.next();
            }else{
                object.addKeyAndValue(key,value);
                return object;
            }

            if (token.getTokenType() == TokenType.IDENTIFIER && layer != token.getLayer()){
                return object;
            }
            else if (token.getTokenType() == TokenType.ARRAY){
                value = parseArray(layer);
            }else{
                value = new JsonElement(token);

            }
            object.addKeyAndValue(key, value);
            if(it1.hasNext()){
                token = it1.next();
            }else{
                return object;
            }

        }
    }

    private JsonArray parseArray(int layer) throws LexicalException {
        JsonArray array = new JsonArray();

        for (;;) {
            if(token.getTokenType() == TokenType.IDENTIFIER && token.getLayer() < layer){
                return array;
            }
            layer = token.getLayer();
            if(it1.hasNext()){
                token = it1.next();
            }else{
                return array;
            }
            if (token.getTokenType() == TokenType.ARRAY && token.getLayer() == layer) {
                array.addValue(parseArray(layer));
            } else if(token.getTokenType() == TokenType.ARRAY && token.getLayer() != layer){
                return array;
            }

            else if (token.getTokenType() == TokenType.IDENTIFIER && token.getLayer() >= layer) {
                array.addValue(parseObject(layer));
            } else if(token.getTokenType() == TokenType.IDENTIFIER && token.getLayer() < layer){
                return array;
            }
            else {
                array.addValue(new JsonElement(token));
            }

        }
    }


}
