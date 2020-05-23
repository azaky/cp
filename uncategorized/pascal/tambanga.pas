var
    ans,temp,j,n,m,prev,i,many,site:longint;
    ar:array[-10..1000000] of longint;
    vis:array[-10..1000000] of boolean;
begin
    readln(m,n);
    prev:=0;
 
    for i:=0 to n do
    begin
        if (m=0) then break;
        if (vis[i]) then
        begin
            temp:=0; continue;
        end;
        dec(m);
        vis[i]:=true;
        writeln(i);
        flush(output);
        readln(many,site);
        ar[i]:=site;
        for j:=i downto i-3 do dec(many,ar[j]);
        if (many+site-temp<2) and (temp<>0) then
        begin
            ar[i+3]:=many+site-temp;
            vis[i+3]:=true;
            temp:=0;
        end;
        temp:=many;
         
    end;
     
    writeln('EMAS');
    for i:=0 to n do if (ar[i]=1) then writeln(i);
    writeln('END');
    flush(output);
end.