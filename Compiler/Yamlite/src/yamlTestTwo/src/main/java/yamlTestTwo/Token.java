package yamlTestTwo;




public class Token {

    public Token(TokenType tokenType) {
        //this.name = name;
        this.tokenType = tokenType;
    }

//    private Token(TokenType tokenType, String data) {
//        //this.name = name;
//        this.data = data;
//    }

//    public Token(TokenType tokenType, int layer, boolean isArrayelement){
//        //this.name = name;
//
////        this.data = data;
//        this.layer = layer;
//        this.isArrayElement = isArrayelement;
//    }

    private int layer = 0;
    private TokenType tokenType;
    private String data;
    private boolean isArrayElement;



    public Token addData(String data) {
        this.data = data;
        return this;
    }

    public Token addLayer(int layer, boolean isArrayElement){
        this.layer = layer;
        this.isArrayElement = isArrayElement;
        return this;
    }

    public TokenType getTokenType(){
        return this.tokenType;
    }

    public boolean getIsArrayElement(){
        return this.isArrayElement;
    }

    public int getLayer(){
        return this.layer;
    }



//
    @Override
    public String toString() {
        return this.data;
    }

}
