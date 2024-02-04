import java.io.*;
import java.util.ArrayList;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 *
 * @author Gürkan Kahraman gurkan.kahraman@ogr.sakarya.edu.tr
 * @since 10.04.2023
 *        <p>
 *        Main Sınıfı ve tüm işlemler ve metodlar burada gerçekleşmektedir
 *        </p>
 */
public class Main {
    public static void main(String[] args) throws IOException {
        if (args.length == 0) {
            System.out.println("Lütfen bir dosya girin.");
            return;
        }
        String fileName = args[0];
        BufferedReader br = new BufferedReader(new FileReader(fileName));
        int singleCommentCount = 0;
        int multiLineCommentCount = 0;
        int javaDocCount = 0;
        String functionName = "";
        ArrayList<String> jvdc = new ArrayList<String>();
        ArrayList<String> singleComment = new ArrayList<String>();
        ArrayList<String> multiComment = new ArrayList<String>();
        BufferedWriter bwSingle = new BufferedWriter(new FileWriter("teksatir.txt"));
        BufferedWriter bwMulti = new BufferedWriter(new FileWriter("coksatir.txt"));
        BufferedWriter bwJDoc = new BufferedWriter(new FileWriter("javadoc.txt"));
        boolean isInsideFunction = false;
        boolean isInsideJavadoc = false;
        int braceCount = 0;
        int firstFunctionTest = 0;
        String line;
        while ((line = br.readLine()) != null) {
            line = line.trim();
            Pattern classDeclarationPattern = Pattern.compile("^\\s*public\\s+class\\s+(\\w+)");
            Matcher classDeclarationMatcher = classDeclarationPattern.matcher(line);
            if (classDeclarationMatcher.find()) {
                String className = classDeclarationMatcher.group(1);
                System.out.println("Sınıf Adı: " + className);
                continue;
            }
            int index = line.indexOf('(');
            if (index != -1) {
                String[] words = line.substring(0, index).split(" ");
                String functionName2 = words[words.length - 1].trim();
                if (isJavaIdentifier(functionName2)
                        && (line.contains("public") || line.contains("private") || line.contains("protected"))) {
                    functionName = functionName2;
                }
            }
            if (line.contains("/**") && !isInsideFunction) {
                isInsideJavadoc = true;
            }
            if (line.contains("{")) {
                braceCount++;
                if (!isInsideFunction) {
                    isInsideFunction = line.contains(functionName);
                    firstFunctionTest += 2;
                }
            } else if (line.contains("}")) {
                braceCount--;
                isInsideFunction = false;
            } else if (isInsideFunction) {
                if (line.contains("//")) {
                    singleCommentCount++;
                    int commentStart = line.indexOf("//");
                    line = line.substring(commentStart).trim();
                    singleComment.add(line);
                }
                if (line.contains("/**")) {
                    javaDocCount++;
                    if (line.contains("/**") && line.contains("*/")) {
                        String start = "/**";
                        String stop = "*/";
                        int index1 = line.indexOf(start);
                        int index2 = line.indexOf(stop);
                        if (index1 != -1 && index2 != -1) {
                            String newJdoc = line.substring(index1 + start.length(), index2);
                            jvdc.add(newJdoc);
                            continue;
                        }
                    } else {
                        jvdc.add(line);

                    }
                    while ((line = br.readLine()) != null && !line.contains("*/")) {
                        if (functionControl(line)) {
                            isInsideFunction = false;
                            braceCount--;
                            break;
                        } else {
                            jvdc.add(line);
                        }
                    }
                    jvdc.add(line);
                }
                if (line.contains("/*")) {
                    if (isInsideJavadoc == true)
                        continue;
                    multiLineCommentCount++;
                    if (line.contains("/*") && line.contains("*/")) {
                        String start = "/*";
                        String stop = "*/";
                        int index1 = line.indexOf(start);
                        int index2 = line.indexOf(stop);
                        if (index1 != -1 && index2 != -1) {
                            String newMulti = line.substring(index1, index2 + stop.length());
                            multiComment.add(newMulti);
                            continue;
                        }

                    } else {
                        multiComment.add(line);
                    }
                    while ((line = br.readLine()) != null && !line.contains("*/")) {
                        if (functionControl(line)) {
                            isInsideFunction = false;
                            braceCount--;
                            break;
                        } else {
                            multiComment.add(line);
                        }

                    }
                    if (line.contains("*/")) {
                        multiComment.add(line);
                    }
                }

            }
            if (!multiComment.isEmpty() && braceCount == 0) {
                bwMulti.write(functionName + ":\n");
                for (String item : multiComment) {
                    bwMulti.write(item);
                    bwMulti.newLine();
                }
                bwMulti.write("------------------------");
                bwMulti.newLine();
            }
            if (!singleComment.isEmpty() && braceCount == 0) {
                bwSingle.write(functionName + ":\n");
                for (String item : singleComment) {
                    bwSingle.write(item);
                    bwSingle.newLine();
                }
                bwSingle.write("------------------------");
                bwSingle.newLine();
            }
            if (braceCount == 0 && isInsideJavadoc) {
                if (line.contains("/**")) {
                    javaDocCount++;
                    jvdc.add(line);
                    while ((line = br.readLine()) != null && !line.contains("*/")) {
                        jvdc.add(line);

                    }
                    jvdc.add(line);
                }
                isInsideJavadoc = false;

            }
            if (braceCount == 0 && !isInsideFunction && firstFunctionTest >= 2) {
                if (!jvdc.isEmpty()) {
                    bwJDoc.write(functionName + ": \n");
                    for (String item : jvdc) {
                        bwJDoc.write(item);
                        bwJDoc.newLine();
                    }
                    bwJDoc.write("------------------------");
                    bwJDoc.newLine();
                }
                System.out.println("Fonksiyon Adı: " + functionName);
                System.out.println("Tek Satır Yorum Sayısı: " + singleCommentCount);
                System.out.println("Çok Satırlı Yorum Sayısı: " + multiLineCommentCount);
                System.out.println("JavaDoc Yorum Sayısı: " + javaDocCount);
                System.out.println("----------------------------------");
                singleCommentCount = 0;
                multiLineCommentCount = 0;
                javaDocCount = 0;
                functionName = "";
                firstFunctionTest = 0;
                singleComment.clear();
                jvdc.clear();
                multiComment.clear();
            }
        }
        br.close();
        bwSingle.close();
        bwMulti.close();
        bwJDoc.close();
    }

    private static boolean isJavaIdentifier(String s) {
        if (s.length() == 0 || !Character.isJavaIdentifierStart(s.charAt(0))) {
            return false;
        }
        for (int i = 1; i < s.length(); i++) {
            if (!Character.isJavaIdentifierPart(s.charAt(i))) {
                return false;
            }
        }
        return true;
    }

    public static boolean functionControl(String line) {
        if (line.contains("}")) {
            return true;
        } else {
            return false;
        }
    }
}
