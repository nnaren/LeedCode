
bool match(const char * s, const char * mask) {
    if(*mask == '\0') {
        return *s == '\0';
    } else if (*mask == '?') {
        return (*s != '\0') && match(s + 1, mask + 1);
    } else if (*mask == '*') {
        return match(s, mask + 1) || match(s + 1, mask);
    } else { // 贪婪与非贪婪调整顺序即可
        return (*s == *mask) && match(s + 1, mask + 1);
    }  
}