export interface IRulesObject {
    exclude?: Array<string>;
    include?: Array<string>;
    matchBasename?: boolean;
    matchPath?: boolean;
    ignoreRootName?: boolean;
}
