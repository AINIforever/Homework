
import javax.script.AbstractScriptEngine;
import javax.script.Bindings;
import javax.script.ScriptContext;
import javax.script.ScriptEngineFactory;
import javax.script.ScriptException;
import javax.script.SimpleBindings;

import java.io.Console;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Stack;  
  
public class Calculate {  
  
    //运算符优先级  
    private static HashMap<String,Integer> opLs; 
    
      
    private String src;  
    private String var;
    private ScriptContext context;
    private double result;
  
    public Calculate(String src, String script, ScriptContext context) throws ScriptException {
    	//context.setAttribute(string, value,ScriptContext.ENGINE_SCOPE);
    	this.context = context;
        //this.src = src;
    	if(cutOutVariable(src)!= null) {
    		this.var = cutOutVariable(src);
    		
    	}
    	this.src = cutOutExpression(src);
		
        if(opLs==null)  
        {  
            opLs = new HashMap<String,Integer>(6);  
            opLs.put("+",0);  
            opLs.put("-",0);  
            opLs.put("*",1);  
            opLs.put("/",1);  
            opLs.put("%",1);  
            opLs.put(")",2);  
        }  
        
        //this.result = getRes();
        
    }  
    
    public void setResult() throws ScriptException {
    	this.result = getRes();
    }
    
    public double getResult() {
    	return this.result;
    }
  
    //将中缀表达式转化为后缀表达式  
    public String toRpn() throws ScriptException  
    {  
        String[] tmp = split(src);  
        // 后缀栈  
        Stack<String> rpn = new Stack<String>();  
        // 临时栈  
        Stack<String> tmpSta = new Stack<String>();  
  
        for (String str : tmp) {  
        	
            if (isNum(str)) { 
            	if(((Character.isLetter(str.charAt(0))))) {
            		str = ""+context.getAttribute(str, ScriptContext.ENGINE_SCOPE);
            		if(str.equals("")) {
            			
            			throw new ScriptException("undefined identifier");
            			
            		}
            			
            	}
            		
            		
                //是操作数,直接压入结果栈  
                rpn.push('('+str+')');  
            }else{  
                //是操作符号  
                if(tmpSta.isEmpty())  
                {//还没有符号  
                    tmpSta.push(str);  
                }else{  
                 //判读当前符号和临时栈栈顶符号的优先级  
                    if(isHigh(tmpSta.peek(),str))  
                    {  
                        if(!str.equals(")"))  
                        {  
                            do{  
                                //1在临时栈中找出小于当前优先级的操作符  
                                //2压入当前读入操作符  
                                rpn.push(tmpSta.peek());  
                                tmpSta.pop();  
                            }while(!tmpSta.isEmpty()&&(isHigh(tmpSta.peek(),str)));  
                              
                            tmpSta.push(str);  
                        }else{  
                            //是)依次弹出临时栈的数据，直到(为止  
                            while(!tmpSta.isEmpty()&&!tmpSta.peek().equals("("))  
                            {  
                                rpn.push(tmpSta.pop());  
                            }  
                            if((!tmpSta.empty())&&(tmpSta.peek().equals("(")))  
                            {//弹出(  
                                tmpSta.pop();  
                            }  
                        }  
                    }else if(!isHigh(tmpSta.peek(),str)){  
                        tmpSta.push(str);  
                    }  
                }  
            }  
  
        }  
        while(!tmpSta.empty())  
        {//把栈中剩余的操作符依次弹出  
            rpn.push(tmpSta.pop());  
        }  
        StringBuilder st = new StringBuilder();  
        for (String str : rpn) {  
                st.append(str);  
        }  
        rpn.clear();  
        return st.toString();  
    }  
  
    //分割(56+4)3*6+2=>(,56,+,4,  
    private String[] split(String src) {  
        StringBuilder sb = new StringBuilder(src.length());  
        for(char ch:src.toCharArray())  
        {  
//            if(ch=='+'||ch=='-'||ch=='*'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='%')  
//            {  
//                sb.append(",");  
//                sb.append(ch);  
//                sb.append(",");  
//            }else{  
//                sb.append(ch);  
//            }  
            if(ch=='+'||ch=='-'||ch=='*'||ch=='*'||ch=='/'||ch==')'||ch=='%')  
            {  
                sb.append(",");  
                sb.append(ch);  
                sb.append(",");  
            }else if(ch=='(') {
            	sb.append(ch);
            	sb.append(',');
            }
            else{  
                sb.append(ch);  
            }
        }  
        String string = sb.toString().replaceAll(",{2,}", ",");  
        return string.split(",");  
    }  
  
    //比较操作符的优先级  
    private boolean isHigh(String pop, String str) {  
        if(str.equals(")"))  
            return true;  
        if(opLs.get(pop)==null||opLs.get(str)==null)  
          return false;  
        return opLs.get(pop)>=opLs.get(str);  
              
    }  
  
    //是否是数字  
    public boolean isNum(String str) {  
        for (char ch : str.toCharArray()) {  
            if(ch=='+'||ch=='-'||ch=='*'||ch=='*'||ch=='/'||ch=='('||ch==')'||ch=='%')  
                return false;  
        }  
        return true;  
    }  
    
    
    
    //得到结果  
    public double getRes() throws ScriptException {  
        String rpn = toRpn();  
        Stack<Double> res = new Stack<Double>();  
        StringBuilder sb = new StringBuilder();  
        for(char ch:rpn.toCharArray())  
        {   
            if(ch=='(')  
            {  
                continue;  
            }else if(ch>='0'&&ch<='9'||ch=='.'){  
                sb.append(ch);  
            }else if(ch==')')  
            {  try {
            	 res.push(Double.valueOf(sb.toString()));  
                 sb = new StringBuilder();
            }catch(Exception e) {
            	throw new ScriptException("error");
            }
                 
            }else{  
                 if(!res.empty())  
                 {  
                     Double x = res.pop();  
                     Double y = res.pop();  
                     switch (ch) {  
                    case '+':  
                         res.push(y+x);   
                        break;  
                    case '-':  
                        res.push(y-x);   
                        break;  
                    case '*':  
                        res.push(y*x);   
                        break;    
                    case '%':  
                    case '/':     
                        if(x!=0)  
                        {  
                            double rsd = ch=='%'?y%x:y/x;  
                            res.push(rsd);   
                        }else{  
                             res.clear();  
                             
                             throw new ScriptException("devided by zero");
                             //return -1;  
                        }  
                        break;  
                    }  
            }  
            }  
        }  
        Double result = res.pop();  
        res.clear();  
        this.context.setAttribute(this.var, result,ScriptContext.ENGINE_SCOPE);
        
        return result;  
    }
    //解析成算术式+变量+分号，并做异常处理
    public String cutOutExpression(String str) throws ScriptException {
    	
    	if(isLegal(str)) {
    		if(str.contains("=")) {
    			int startPos = str.indexOf("=");
    			String var = str.substring(0,startPos-1);
    			
    			String expStr =  str.substring(startPos+1,str.length()-1);
    			return expStr;
    		}
    		else {
    			String expStr = str.substring(6,str.length()-2);
    			return expStr;
    		}
    	}
    	
    	
    	else {
    		return null;
    	}
    }
    
    public boolean isLegal(String str) throws ScriptException {
    	//有关分号位置及个数
    	String strTmp = str;
    	int len1 = strTmp.length();
    	String s1 = strTmp.replaceAll(";","");
    	int len2 = s1.length();
    	int count = len1-len2;
    	
    	if((!strTmp.contains(";")) || count>1 || strTmp.indexOf(";")!= strTmp.length()-1) {
    		
    		//return false;
    		
    		throw new ScriptException("expected: ;");
    		
    	}
    	
    	if((!strTmp.contains("=")) && (!strTmp.contains("print"))) {
    		
    		return false;
    	}
    	
    	if((strTmp.contains("=")) && (strTmp.contains("print"))) {
    		
    		return false;
    	}
    	
    	
    	return true;
    }
    
    public String cutOutVariable(String str) {
    	if(str.indexOf("=")!= -1) {
    		int startPos = str.indexOf("=");
    		
    		String vars = str.substring(0,startPos);
    		
        	return vars;
    	}
    	return "result";
    }
    

} 
