module Style = {
  let global = ReactDOMRe.Style.make(~fontFamily="sans-serif", ());

  let title =
    ReactDOMRe.Style.make(
      ~alignItems="flex-start",
      ~borderBottom="2px solid hotpink",
      ~display="flex",
      ~fontSize="18px",
      ~fontWeight="700",
      ~margin="6px 12px",
      ~marginBottom="24px",
      ~paddingBottom="6px",
      (),
    );

  let navigation =
    ReactDOMRe.Style.make(
      ~backgroundColor="#f9f9f9",
      ~borderRight="1px solid #eaeaea",
      ~bottom="0px",
      ~display="flex",
      ~flexDirection="column",
      ~left="0px",
      ~listStyleType="none",
      ~padding="32px 12px",
      ~position="fixed",
      ~top="0px",
      ~width="256px",
      (),
    );

  let link = active =>
    ReactDOMRe.Style.make(
      ~color="black",
      ~fontWeight={
        active ? "700" : "500";
      },
      ~margin="6px 12px",
      ~textDecoration="none",
      (),
    );
};

[@react.component]
let make = () => {
  let url =
    ReasonReactRouter.useUrl(
      ~serverUrl="https://lessp.github.io/bs-react-is-visible/",
    );

  let (example, currentUrl) =
    switch (url.path) {
    | ["basic"]
    | [] => (<Basic />, "basic")
    | ["lazyload"] => (<LazyLoad />, "lazyload")
    | _ => (
        <h1 style={ReactDOMRe.Style.make(~paddingLeft="320px", ())}>
          {"Nothing to see here..." |> React.string}
        </h1>,
        "",
      )
    };

  <div style=Style.global>
    <nav style=Style.navigation>
      <h1 style=Style.title> {"bs-react-is-visible" |> React.string} </h1>
      <a
        href="/basic"
        title="Basic"
        style={Style.link(currentUrl === "basic")}>
        {"Basic" |> React.string}
      </a>
      <a
        href="/lazyload"
        title="LazyLoad"
        style={Style.link(currentUrl === "lazyload")}>
        {"Lazy Load" |> React.string}
      </a>
    </nav>
    example
  </div>;
};
