module Style = {
  let wrapper =
    ReactDOMRe.Style.make(
      ~alignItems="center",
      ~display="grid",
      ~fontFamily="sans-serif",
      ~gridGap="32px",
      ~justifyContent="center",
      (),
    );

  let box =
    ReactDOMRe.Style.make(
      ~alignItems="center",
      ~backgroundColor="hotpink",
      ~color="white",
      ~display="flex",
      ~fontSize="32px",
      ~height="256px",
      ~justifyContent="center",
      (),
    );
};

[@react.component]
let make = () => {
  let (isVisible, ref) = ReactIsVisible.useIsVisible();
  let (items, setItems) = React.useState(() => [|0, 0, 0, 0|]);

  React.useEffect1(
    () => {
      isVisible
        ? setItems(currentItems =>
            currentItems |> Array.append([|0, 0, 0, 0|])
          )
        : ();

      None;
    },
    [|isVisible|],
  );

  <div style=Style.wrapper>
    {items
     |> Array.mapi((i, _item) =>
          <div key={string_of_int(i)} style=Style.box>
            {string_of_int(i) |> React.string}
          </div>
        )
     |> React.array}
    <span ref>
      {"When you see this, more items will load" |> React.string}
    </span>
  </div>;
};
