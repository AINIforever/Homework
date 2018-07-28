package yamlTestTwo.JsonUtil;

import java.util.LinkedHashMap;
import java.util.Map;

public class JsonObject extends JsonFormat{

    private ValueType type;

    private Map<String, JsonValue> map;

    public JsonObject() {
        map = new LinkedHashMap<String, JsonValue>();
        type = ValueType.OBJECT;
    }

    public void addKeyAndValue(String key, JsonValue value) {
        map.put(key, value);
    }

    public JsonValue getValue(String key) {
        return map.get(key);
    }

    @Override
    public String toString() {
        return format(1);
    }

    public ValueType getType() {
        return type;
    }

    public Map<String, JsonValue> getMap(){
        return this.map;
    }

    @Override
    String format(int layer) {
        StringBuilder str = new StringBuilder();
        str.append("{\n");
        for (Map.Entry entry : map.entrySet()) {
            str.append(withSpace(layer));
            str.append("\"" + entry.getKey() + "\"");
            str.append(": ");
            str.append(matchFormat(entry.getValue(), layer+1));
            str.append(",\n");
        }
        int lastIndex = str.length() - 2;
        if (str.charAt(lastIndex) == ',') str.deleteCharAt(lastIndex);
        str.append(withSpace(layer-1));
        str.append("}");
        return str.toString();
    }
}

