package yamlTestTwo.JsonUtil;

import java.math.BigDecimal;

public enum ValueType {
    OBJECT("object"),
    ARRAY("array"),
    INT("int"),
    FLOAT("float"),
    STRING("string"),
    BOOL("bool"),
    BIGDECIMAL("bigdecimal");


    private String type;

    private ValueType(String type) {
        this.type = type;
    }

    public String getType() {
        return type;
    }
}
