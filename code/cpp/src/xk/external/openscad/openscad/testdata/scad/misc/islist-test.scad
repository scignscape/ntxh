echo("returning true");
echo(is_list([]));
echo(is_list([1]));
echo(is_list([1,2]));
echo(is_list([true]));
echo(is_list([1,2,[5,6],"test"]));
echo("--------");
echo("returning false");
echo(is_list(1));
echo(is_list(1/0));
echo(is_list(((1/0)/(1/0))));
echo(is_list("test"));
echo(is_list(true));
echo(is_list(false));
echo("--------");
echo("causing warnings:");
echo(is_list());
echo(is_list(1,2));