package yamlTestTwo;

import yamlTestTwo.JsonUtil.*;
import java.util.Iterator;
import java.util.Map;

public class Find {

    public static JsonFormat returnJsonFormat(String key, JsonFormat json){
        Iterator<Map.Entry<String, JsonValue>> iterator= ((JsonObject) json).getMap().entrySet().iterator();
        while(iterator.hasNext())
        {
            Map.Entry entry = iterator.next();
            if(entry.getKey().toString().equals(key)){
                json = (JsonFormat) entry.getValue();
            }

        }
        return json;

    }



    public static JsonValue returnJsonValue(String key, JsonFormat json){
        JsonValue jsonValue = null;
        Iterator<Map.Entry<String, JsonValue>> iterator= ((JsonObject) json).getMap().entrySet().iterator();
        while(iterator.hasNext())
        {
            Map.Entry entry = iterator.next();
            if(entry.getKey().toString().equals(key)){
                jsonValue = (JsonValue) entry.getValue();
            }

        }
        return jsonValue;
    }

    public static int indexCount(String location){
        int n=0;

        while(location.indexOf("[") != -1) {
            int i = location.indexOf("[");
            n++;
            location = location.substring(i+1);
        }
        return n;
    }

    public static String findValue(String location, String path) throws LexicalException {

        JsonValue jsonValue = null;
        Parser parser = new Parser();
        JsonFormat json = parser.parseYaml(path);
        String curKey;

        while(location.contains(".")){
            curKey = location.split("\\.")[0];
            location = location.split("\\.")[1];
            if(curKey.contains("[")){ //数组
                String tmp = curKey;
                curKey = curKey.substring(0,curKey.indexOf("["));
                String indexStr = tmp.substring(tmp.indexOf("[")+1, tmp.indexOf("]"));
                int index = Integer.parseInt(indexStr);

                json = returnJsonFormat(curKey,json);

                Iterator<JsonValue> it1 = ((JsonArray) json).getArray().iterator();
                for(int i=0;i<index;i++){
                    if(it1.hasNext())
                        it1.next();
                }
                JsonValue value = it1.next();
                json = (JsonFormat) value;
            }
            else{ //键值对
                json = returnJsonFormat(curKey,json);
            }
        }

        if(!location.contains(".")){
            Boolean isFirstIndex = true;
            String locationCpy = location;
            while(location.contains("[")){ //数组
                if(!isFirstIndex){
//                    String tmp = location;
//                    curKey= location.substring(0,location.indexOf("["));
                    location = location.substring(1,location.length());
                    String tmp = location;
                    location = location.substring(location.indexOf("]"),location.length());
                    String indexStr = tmp.substring(0,tmp.indexOf("]"));
//                    String indexStr = indexStr.substring(location.indexOf("["), tmp.indexOf("]"));
                    char indexCh = indexStr.charAt(1);
                    int index = Integer.parseInt(String.valueOf(indexCh));

//                    json = returnJsonFormat(json);

                    Iterator<JsonValue> it1 = ((JsonArray) json).getArray().iterator();
                    for(int i=0;i<index;i++){
                        if(it1.hasNext())
                            it1.next();
                    }

                    jsonValue = it1.next();
                }

                if(indexCount(location)==1 || (indexCount(location)!=1 && isFirstIndex)){
                    if(indexCount(location)!=1)
                        isFirstIndex = false;
                    String tmp = location;
                    curKey = location.substring(0,location.indexOf("["));
                    location = location.substring(location.indexOf("]"),location.length());
                    String indexStr = tmp.substring(tmp.indexOf("[")+1, tmp.indexOf("]"));
                    int index = Integer.parseInt(indexStr);

                    json = returnJsonFormat(curKey,json);

                    Iterator<JsonValue> it1 = ((JsonArray) json).getArray().iterator();
                    for(int i=0;i<index;i++){
                        if(it1.hasNext())
                            it1.next();
                    }

                    jsonValue = it1.next();
                }


            }
            if(!locationCpy.contains("[")){ //键值对
                jsonValue = returnJsonValue(location,json);
            }

        }

        return jsonValue.toString();
    }
}
