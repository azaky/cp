var
        n, m, group, i:longint;
        voice:array[1..100000] of longint;
        ind, list:array[0..10000] of longint;
 
procedure sort(a,b:longint);
var
        mid,temp,left,right:longint;
begin
        mid:=voice[(a+b) div 2];
        left:=a;
        right:=b;
        
        while (left<=right) do
        begin
                while (voice[left]<mid) do inc(left);
                while (voice[right]>mid) do dec(right);
                if (left<=right) then
                begin
                        temp:=voice[left]; voice[left]:=voice[right]; voice[right]:=temp;
                        inc(left); dec(right);
                end;
        end;
        if (a<right) then sort(a,right);
        if (left<b) then sort(left,b);
end;
 
procedure bt(post,num:longint);
var
        i:longint;
begin
        if (list[num-1]-1=voice[post]) then exit;
        if (num=m) and (post+group>n) then
        begin
                //for i:=1 to num-1 do writeln(ind[i]);
                for i:=1 to num-1 do
                begin
                        write(list[i]-list[i-1]);
                        if (i<num-1) then write(' ');
                end;
                writeln;
                //halt;
        end;
        list[num]:=voice[post+group-1]+1;
        //ind[num]:=post+group-1;
        bt(post+group,num+1);
        list[num]:=voice[post+group]+1;
        //ind[num]:=post+group;
        bt(post+group+1,num+1);
end;
 
begin
        readln(n);
        for i:=1 to n do readln(voice[i]);
        sort(1,n);
        readln(m);
        //for i:=1 to n do writeln(voice[i]);
        group:=n div m;
        if (n mod m=0) then
        begin
                for i:=1 to n-group do 
                if (i mod group=0) then 
                begin
                        write(voice[i]+1);
                        if (i<n-group) then write(' ');
                end;
                writeln;
        end
        else bt(1,1);
end.
