class Solution {
    public boolean areSentencesSimilar(String sentence1, String sentence2) {
         String[] a = sentence1.split(" ");
        String[] b = sentence2.split(" ");

        int n1 = a.length;
        int n2 = b.length;

        if (n1 > n2) {
            String[] temp = a;
            a = b;
            b = temp;

            int t = n1;
            n1 = n2;
            n2 = t;
        }

        int i = 0;
        int j = n1 - 1;
        int k = n2 - 1;

        while (i < n1 && a[i].equals(b[i])) {
            i++;
        }

        while (j >= i && a[j].equals(b[k])) {
            j--;
            k--;
        }

        return j < i;
    }
}