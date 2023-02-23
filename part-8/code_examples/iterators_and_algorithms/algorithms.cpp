template <typename In, typename X>
In find(In begin, In end, const X& x)
{
    while (begin != end && *begin != x)
    {
        ++begin;
    }
    return begin;
}

template <typename In, typename X>
In find_recursive(In begin, In end, const X& x)
{
    if (begin == end || *begin == x)
    {
        return begin;
    }
    begin++;
    find_recursive(begin, end, x);
}

template <typename In, typename Out>
Out copy(In begin, In end, Out dest)
{
    while (begin != end)
    {
        *dest++ = *begin++;
    }
    return dest;
}

template <typename For, typename X>
void replace(For beg, For end, const X& x, const X& y)
{
    while (beg != end)
    {
        if (*beg == x)
        {
            *beg = y;
        }
        ++beg;
    }
}

template <typename Bi>
void reverse(Bi begin, Bi end)
{
    while (begin != end)
    {
        --end;
        if (begin != end)
        {
            swap(*begin++, *end);
        }
    }
}

template <typename Ran, typename X>
bool binary_search(Ran begin, Ran end, const X& x)
{
    while (begin < end)
    {
        // find the midpoint of the range
        Ran mid = begin + (end - begin) / 2;
        // see which part of the range contains x; keep looking only in that part 
        if (x < *mid)
        {
            end = mid;
        }
        else if (x > *mid)
        {
            begin = mid + 1;
        }
        // if we got here, then *mid == x so we're done 
        else
        {
            return true
        }
    }
    return false;
}
